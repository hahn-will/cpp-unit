#include "utils.hpp"

#include <sys/stat.h>
#include <sstream>
#include <regex>

using namespace std;

time_t utils::since_creation(const string &file) {
  struct stat attr;
  if (stat(file.c_str(), &attr))
    return 0;
  return attr.st_ctim.tv_sec;
}

bool utils::been_compiled(const string input_file,
                   const string output_file) {
  return since_creation(input_file) < since_creation(output_file);
}

bool utils::file_exists(const string &file_name) {
  struct stat attr;
  return (stat(file_name.c_str(), &attr) == 0);
}

string utils::aggregate(const vector<string> &strings) {
  stringstream ss;
  for (const string &s : strings) {
    ss << " " << s;
  }

  return ss.str();
}

bool utils::check_directory(const string &input) {
  return file_exists(input);
}

bool utils::match_method_signature(const string &input_string) {
  stringstream ss;
  ss << "([^ ]+([ ]+)[^ ]+)([ ]*\\:\\:[ ]*[^ :]+)*([ ]*)"
     << "((\\\(\\))|(\\\([^,]\\))|(\\\(([^,]+(\\,([^,]+))*)\\)))([ ]*)"
     <<"((\\\{)|\\;)[ ]*";
  return regex_match(input_string, regex(ss.str()));
}
