#include "preprocessor.hpp"

#include <vector>
#include <string>

using namespace std;

vector<string> preprocessor::process_all(int argc, char **argv) {
  vector<string> output; 
  for (int i = 1; i < argc; i++) {
    output.push_back(argv[i]);
  }
  return output;
}
