#include "Terminal.hpp"

#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <functional>

Terminal::Terminal() {
  if (tcgetattr(STDOUT_FILENO, &terminal_options) < 0)
    throw new std::runtime_error("Failed to get terminal attributes");

  memcpy(&revert_options, &terminal_options, sizeof(struct termios));
  cfmakeraw(&terminal_options);
}


void Terminal::Print(const string printed_string) {
  writing_string += printed_string;
}

void Terminal::Print(const string printed_string, const int x, const int y) {
  stringstream output;
  output << "\033[" << x << ";" << y << "H" << printed_string;
  writing_string += output.str();
}

void Terminal::CreateHierarchyChoice(const Tree *tree) {
  stringstream output;
  int height = 0;

  function<void(string, int)> exec = [&](string value, int depth) {
    height++;
    for (int i = 0; i < depth; i++) {
      output << value;
    }
  };

  tree->DFSTraversal(exec);

  writing_string += output.str();
}

void Terminal::Prompt() {
  fflush(stdout);
  tcsetattr(STDOUT_FILENO, TCSANOW, &terminal_options);
  // Insert prompt handling
  // Insert prompt writing
  // Return array of names selected
  fflush(stdout);
  tcsetattr(STDOUT_FILENO, TCSANOW, &revert_options);
}
