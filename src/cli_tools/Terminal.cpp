#include "Terminal.hpp"

#include <cstdio>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sstream>
#include <functional>

// Default constructor for the Terminal class
// Mostly just initializes values when necessary
// Throws a runtime error when it cannot get the terminal attributes
Terminal::Terminal() {
  if (tcgetattr(STDOUT_FILENO, &terminal_options) < 0)
    throw new std::runtime_error("Failed to get terminal attributes");

  memcpy(&revert_options, &terminal_options, sizeof(struct termios));
  cfmakeraw(&terminal_options);
  writing_string = "";
  prompt_height = 0;
}

// Function to print text to the screen
// Wont write the text to the screen until the prompt function is called
void Terminal::Print(const string printed_string) {
  writing_string += printed_string;
}

// Function to print text to the screen at a location
// Won't write the text to the screen until the prompt function is called
void Terminal::Print(const string printed_string, const int x, const int y) {
  stringstream output;
  output << "\033[" << x << ";" << y << "H" << printed_string;
  writing_string += output.str();
}

// This builds a prompt for the user of the program to choose between
// a group of choices build into a hierarchy
// It is helpful if one choice will run several subchoices
void Terminal::CreateHierarchyChoice(const Tree *tree) {
  stringstream output;

  function<void(string, int)> exec = [&](string value, int depth) {
    prompt_height++;
    for (int i = 0; i < depth; i++) {
      output << "  ";
    }
    output << " + " << value << depth * 2 + 2 << "\n\r";
    prompt_strings.push_back(value);
    prompt_selected.push_back(false);
    cursor_pos.push_back(depth * 2 + 2);
  };

  tree->DFSTraversal(exec);

  writing_string += output.str();
}

// This writes the prompt on the screen. Currently only allows for
// prompting where character input is given
// returns a vector of strings which represent the selected values
vector<string> Terminal::Prompt() {
  fflush(stdout);
  tcsetattr(STDOUT_FILENO, TCSANOW, &terminal_options);
  cout << writing_string;

  cout << "\033[" << prompt_height << "A";
  if (cursor_pos.size() > 0)
    cout << "\033[" << cursor_pos[0] << 'G';

  cout.flush();

  char c = getchar();
  unsigned current_location = 0;

  while (c != 'd' && c != 'q') {
    switch(c) {
      case '\033':
        getchar();
        c = getchar();
        switch(c) {
          case 'A':
            if (current_location > 0) {
              current_location--;
              cout << "\033[A\033[" << cursor_pos[current_location] << 'G';
              cout.flush();
            }
            break;
          case 'B':
            if (cursor_pos.size() > cursor_pos.size() -1 && 
                current_location < cursor_pos.size() - 1) {
              current_location++;
              cout << "\033[B\033[" << cursor_pos[current_location] << 'G';
              cout.flush();
            }
            break;
        }
        break;
    }
    c = getchar();
  }

  cout << "\033[" << prompt_height - current_location << "B\r";

  fflush(stdout);
  tcsetattr(STDOUT_FILENO, TCSANOW, &revert_options);

  vector<string> chosen;

  return chosen;
}

