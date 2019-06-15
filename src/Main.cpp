#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

#include "preprocessor.hpp"
#include "compiler.hpp"

#ifndef CXX_COMPILER
#define CXX_COMPILER "g++"
#endif

using namespace std;

int main(int argc, char *argv[]) {
  vector<string> arguments = preprocessor::process_all(argc, argv);
  arguments.insert(arguments.begin(), CXX_COMPILER);
  string output = "build";
  string f = "test";
  cout << compiler::compile_all(arguments, output, f);
}
