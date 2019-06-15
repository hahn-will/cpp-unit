#include "compiler.hpp"

#include <stdlib.h>
#include <sys/stat.h>
#include <cassert>
#include <sstream>
#include <iostream>

#define COMPILE_SYMBOLS "-Wall -Werror -std=c++11 -c -g -o "
#define LINK_SYMBOLS "-Wall -Werror -std=c++11 -g -o "
#define OBJECT_FILE_EXTENSION ".o"

using namespace std;

time_t since_creation(const string &file) {
  struct stat attr;
  if (stat(file.c_str(), &attr))
    return 0;
  return attr.st_ctim.tv_sec;
}

bool been_compiled(const string input_file,
                   const string output_file) {
  return since_creation(input_file) < since_creation(output_file);
}

void build_required_directories(const string &file) {
  int loc = file.find_last_of('/');
  string sub = file.substr(0, loc);
  stringstream ss;
  ss << "mkdir -p " << sub;
  system(ss.str().c_str());
}

bool compile_file(const string &compiler,
                  const string &source_file,
                  const string &output_file) {
  stringstream ss;
  ss << compiler << " " << COMPILE_SYMBOLS << output_file << " " << source_file;
  return system(ss.str().c_str());
}

void write_failed_build(const string &source_file,
                        const string &output_file) {
  cout << source_file << " " << output_file;
}

string compiler::compile_all(vector<string> &arguments,
                             const string &output_folder,
                             const string &output_file) {
  assert(arguments.size() > 0);
  string compiler  = arguments[0];

  stringstream ret;

  vector<string> output_files;

  for (unsigned i = 1; i < arguments.size(); i++) {
    stringstream ss;
    ss << output_folder << "/" << arguments[i] << OBJECT_FILE_EXTENSION;
    output_files.push_back(ss.str());
    if (!been_compiled(arguments[i], ss.str())) {
      build_required_directories(ss.str());
      if (compile_file(compiler, arguments[i], ss.str())) {
        write_failed_build(arguments[i], ss.str());
        ret << "failed on " << ss.str() << endl;
      }
    }
  }

  stringstream ss;
  ss << compiler << " " << LINK_SYMBOLS << output_folder << "/" << output_file;

  for (string &s : output_files) {
    ss << " " << s;
  }

  if (system(ss.str().c_str())) {
    write_failed_build(output_folder, output_file);
    ret << "failed on " << output_file << endl;
  }

  return ret.str();
}
