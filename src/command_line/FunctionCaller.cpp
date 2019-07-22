#include "FunctionCaller.hpp"

FunctionCaller::FunctionCaller(vector<string> *input_files) {
  files_to_compile = input_files;
  save_report = false;
  BuildMakefile();
}

FunctionCaller::FunctionCaller(vector<string> *input_files, bool csv_report) {
  files_to_compile = input_files;
  save_report = csv_report;
  BuildMakefile();
}

void FunctionCaller::HandleTestCases() {

}

void FunctionCaller::BuildMakefile() {
  stringstream ss;
  ss << "all:";
  for (string &s : *files_to_compile) {
    ss << " " << s;
  }
  ss << "\n\n";

  for (string &s : *files_to_compile) {
    ss << s << files_to_compile;
  }

}
