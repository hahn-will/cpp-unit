#include "compiler.hpp"

#include <cassert>
#include <sstream>
#include <iostream>

#include "utils.hpp"

#define COMPILE_SYMBOLS "-Wall -Werror -std=c++11 -c -g -o "
#define LINK_SYMBOLS "-Wall -Werror -std=c++11 -g -o "
#define OBJECT_FILE_EXTENSION ".o"
#define CREATE_FOLDER_COMMAND "mkdir -p "

using namespace std;

void build_required_directories(const string &file) {
  int loc = file.find_last_of('/');
  string sub = file.substr(0, loc);
  stringstream ss;
  ss << CREATE_FOLDER_COMMAND << sub;
  system(ss.str().c_str());
}

bool compile_file(const string &compiler,
                  const string &source_file,
                  const string &output_file) {
  if (!utils::file_exists(source_file)) {
    return true;
  }

  stringstream ss;
  ss << compiler << " " << COMPILE_SYMBOLS << output_file << " " << source_file;
  return system(ss.str().c_str());
}

void write_failed_build(const string &source_file,
                        const string &output_file) {
  cout << source_file << " " << output_file;
}

string create_output_file_name(const string &source_file) {
  stringstream ss;
  ss << source_file << OBJECT_FILE_EXTENSION;
  return ss.str();
}

bool link_object_files(const string &compiler,
                       const string &output_file_name,
                       const string &input_files) {
  stringstream ss;
  ss << compiler << " " << LINK_SYMBOLS
     << output_file_name << input_files; 
  return system(ss.str().c_str());
}

string compiler::compile_all(vector<string> &arguments,
                             const string &output_file) {
  assert(arguments.size() > 0);
  string compiler  = arguments[0];

  stringstream ret;

  vector<string> output_files;

  for (unsigned i = 1; i < arguments.size(); i++) {
    output_files.push_back(create_output_file_name(arguments[i]));
    if (compile_file(compiler,
                      arguments[i],
                      output_files.back())) {
      ret << "[" << RED << "FAILED" << RESET << "] Compilation step ";
      ret << "'" << arguments[i] << "' failed compiling into '";
      ret << output_files.back() << "'" << endl;
    }
  }

  string agg = utils::aggregate(output_files);

  if (!link_object_files(compiler, output_file, agg)) {
    ret << "[" << RED << "FAILED" << RESET << "] Compilation step ";
    ret << "failed compiling into '" << output_file << "'" << endl;
  }

  return ret.str();
}
