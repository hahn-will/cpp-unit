#include "preprocessor.hpp"

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "utils.hpp"

#define OBJECT_FILE_EXTENSION ".o"
#define PREPROCESSED_PREFIX "p."

#define DEFAULT_OUTPUT_NAME "a.out"

#define OUTPUT_FLAG "-o"
#define LIBRARY_PATH_FLAG "-L"
#define LIBRARY_NAME_FLAG "-l"

#define MISSING_ARGUMENT \
  "Finding file target: missing argument after flag: "

#define MISSING_FILE \
  "Finding input file: the following file does not exist: "

using namespace std;
using namespace utils;

#define LOG_TARGET_FILE_ERROR(stream, argument_details, output_flag) \
  stream << "[" << RED << "FAILED" << "]" << " Failed on preprocessing step: " \
  << argument_details << output_flag;

#define LOG_MISSING_FILE_ERROR(stream, flag) \
  LOG_TARGET_FILE_ERROR(stream, MISSING_ARGUMENT, flag)

#define LOG_OUTPUT_ERROR(stream) \
  LOG_MISSING_FILE_ERROR(stream, OUTPUT_FLAG)

#define LOG_LIBRARY_PATH_ERROR(stream) \
  LOG_MISSING_FILE_ERROR(stream, LIBRARY_PATH_FLAG)

#define LOG_LIBRARY_NAME_ERROR(stream) \
  LOG_MISSING_FILE_ERROR(stream, LIBRARY_NAME_FLAG)

#define LOG_MISSING_INPUT_FILE(stream, file_name) \
  stream << MISSING_FILE << file_name;

#define TEST_METHOD "TestMethod"
#define TEST_SUITE "TestSuite"
#define TEST_CASE "TestCase"
#define DATA_METHOD "DataMethod"

string preprocess_file(const string &input_file, const string &output_file) {
  ifstream infile(input_file);
  ofstream outfile(output_file);

  stringstream ss;

  if (infile.fail()) {
    LOG_MISSING_INPUT_FILE(ss, input_file);
    return ss.str();
  }

  vector<string> words;

  string word;
  while (infile >> word) {}

  for (unsigned i = 0; i < words.size(); i++) {
    word = words[i];

    if (word.size() > 2 && word[i] == '[') {
      if (word[word.size() - 1] == ']') {
        string sub = word.substr(1, word.size() - 1);
        if (sub == TEST_METHOD) {
          
        }
        else if (sub == TEST_CASE) {

        }
        else if (sub == DATA_METHOD) {

        }
        else if (sub == TEST_SUITE) {

        }
        else {
          outfile << word << " ";
        }
      }
      else {
        outfile << word << " ";
      }
    }
    else {
      outfile << word << " ";
    }
  }
}

vector<string> preprocessor::process_all(int argc,
                                         char **argv,
                                         flag_options &flags) {
  vector<string> output;
  flags.output_filename = DEFAULT_OUTPUT_NAME;
  flags.output_directory = "";
  stringstream error_output;
  for (int i = 1; i < argc; i++) {
    string s = argv[i];
    if (s == OUTPUT_FLAG) {
      if (++i < argc) {
        flags.output_filename = argv[i];
      }
      else {
        LOG_OUTPUT_ERROR(error_output);
      }
    }
    else if (s == LIBRARY_PATH_FLAG) {
      if (++i < argc) {
        flags.library_path.push_back(argv[i]);
      }
      else {
        LOG_LIBRARY_PATH_ERROR(error_output);
      }
    }
    else if (s == LIBRARY_NAME_FLAG) {
      if (++i < argc) {
        flags.library_name.push_back(argv[i]);
      }
      else {
        LOG_LIBRARY_NAME_ERROR(error_output);
      }
    }
    else {
      stringstream prependedf;
      prependedf << PREPROCESSED_PREFIX << argv[i];
      output.push_back(prependedf.str());
      error_output << preprocess_file(argv[i], output.back());
    }
  }

  flags.error = error_output.str();

  return output;
}
