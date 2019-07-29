#include "CommandLine.hpp"

#define MIN_NUM_ARGS 2

CommandLine::CommandLine(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    args.push_back(argv[i]);
  }
}

CommandLine::~CommandLine() {

}

bool CommandLine::ProcessArgs() {
  if (args.size() < MIN_NUM_ARGS)
    return false;

  for (unsigned i = 1; i < args.size(); i++)
    input_files.push_back(args[i]);
  return true;
}

vector<string> *CommandLine::GetInputFiles() {
  return new vector<string>(input_files);
}
