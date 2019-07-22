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

string make_object_filename(const string filename) {
  string new_filename = filename + ".o";
  return new_filename;
}

string make_shared_library_filename(const string filename) {
  string new_filename = filename + ".so";
  return new_filename;
}

vector<string> make_object_filenames(const vector<string> cpp_files) {
  vector<string> output;
  for (const string &s : cpp_files) {
    output.push_back(make_object_filename(s));
  }
  return output;
}

vector<string> make_shared_library_filenames(const vector<string> cpp_files) {
  vector<string> output;
  for (const string &s : cpp_files) {
    output.push_back(make_object_filename(s));
  }
  return output;
}

void make_instruction(stringstream &ss, const string output,
    const vector<string> dep) {
  ss << output << ":";

  for (const string &s : dep) {
    ss << " " << s;
  }
}

void make_all_instruction(stringstream &ss, vector<string> dependencies) {
  make_instruction(ss, "all", dependencies);
  ss << endl << endl;
}

string make_exec_string(const string cpp_file, const string obj_file) {
  return "g++ -MM -MQ " + cpp_file + " " + obj_file;
}

string make_objectfile_dependency(const string cpp_file,
    const string obj_file) {
  return exec_to_string(make_exec_string(cpp_file, obj_file).c_str());
}

string build_object_file_exec_string(const string cpp_file,
    const string obj_file, const string extra_flags) {
  return "g++ -fPIC -c -o " + obj_file + " " + cpp_file + " " + extra_flags;
}

void FunctionCaller::BuildMakefile() {
  stringstream ss;

  vector<string> object_filenames = make_object_filenames(*files_to_compile);
  vector<string> shared_library_filenames =
    make_shared_library_filenames(*files_to_compile);

  for (unsigned i = 0; (i < (*files_to_compile).size()) &&
                       (i < object_filenames.size()); i++) {
    ss << make_objectfile_dependency(files_to_compile->at(i),
        object_filenames.at(i)) << "\t";
    ss << build_object_file_exec_string(files_to_compile->at(i),
        object_filenames.at(i), "") << endl << endl;
  }

  for (unsigned i = 0; (i < object_filenames.size()) &&
                       (i < shared_library_filenames.size()); i++) {
  }
}
