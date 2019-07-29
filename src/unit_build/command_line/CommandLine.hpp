#ifndef COMMAND_LINE_HPP__
#define COMMAND_LINE_HPP__

#include <vector>
#include <string>

#include "../utils/ProcessHandler.hpp"

using namespace std;

class CommandLine : public ProcessHandler {
  public:
    CommandLine(int, char **);
    ~CommandLine();

    bool ProcessArgs();

    vector<string> *GetInputFiles();

  private:
    vector<string> input_files;
    vector<string> args;
};

#endif
