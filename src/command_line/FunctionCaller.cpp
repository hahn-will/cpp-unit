#include "FunctionCaller.hpp"

#include <iostream>

// Constructor with default settings and list of input_files
FunctionCaller::FunctionCaller(vector<string> *input_files) {
  files_to_compile = input_files;
  save_report = false;
  BuildMakefile();
}

// Constructor for creating a csv_report (requires implementation)
FunctionCaller::FunctionCaller(vector<string> *input_files, bool csv_report) {
  files_to_compile = input_files;
  save_report = csv_report;
  BuildMakefile();
}

FunctionCaller::~FunctionCaller() {
  delete(files_to_compile);
}

// Handles the Test Cases
void FunctionCaller::HandleTestCases() {

}

// Creates one object filename
string make_object_filename(const string filename) {
  string new_filename = filename + ".o";
  return new_filename;
}

// Creates one shared library filename
string make_shared_library_filename(const string filename) {
  string new_filename = filename + ".so";
  return new_filename;
}

// Creates the object filenames for an entire list of filenames
vector<string> make_object_filenames(const vector<string> cpp_files) {
  vector<string> output;
  for (const string &s : cpp_files) {
    output.push_back(make_object_filename(s));
  }
  return output;
}

// Builds the shared library filenames for an entire list of cpp files
vector<string> make_shared_library_filenames(const vector<string> cpp_files) {
  vector<string> output;
  for (const string &s : cpp_files) {
    output.push_back(make_shared_library_filename(s));
  }
  return output;
}

// creates an instruction given a list of dependencies, the output, and a stream
// to write it to
void make_instruction(stringstream &ss, const string output,
    const vector<string> dep) {
  ss << output << ":";

  for (const string &s : dep) {
    ss << " " << s;
  }
}

// Creates the "all" instruction
void make_all_instruction(stringstream &ss, vector<string> dependencies) {
  make_instruction(ss, "all", dependencies);
  ss << endl << endl;
}

// Creates the string to get the dependencies
string make_exec_string(const string cpp_file, const string obj_file) {
  return "g++ -MM -MQ " + obj_file + " " + cpp_file;
}

// Creates the dependencies for each object file instruction
// Executes command
string make_objectfile_dependency(const string cpp_file,
    const string obj_file) {
  return exec_to_string(make_exec_string(cpp_file, obj_file).c_str());
}

// helper function to create the exec_string for building object files
string build_object_file_exec_string(const string cpp_file,
    const string obj_file, const string extra_flags) {
  return "g++ -fPIC -c -o " + obj_file + " " + cpp_file + " " + extra_flags;
}

// Helper function to create the makefile
// Used in the constructors
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
    ss << shared_library_filenames.at(i) << ": " << object_filenames.at(i);
    ss << endl << "\tg++ -fPIC -shared -o " << shared_library_filenames.at(i);
    ss << " " << object_filenames.at(i) << endl << endl;
  }

  cout << ss.str() << endl;
}
