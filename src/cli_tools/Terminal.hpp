#ifndef TERMINAL_HPP__
#define TERMINAL_HPP__

#include "Tree.hpp"

#include <string>
#include <termios.h>

using namespace std;

// Declaration for the class 'Terminal'
class Terminal {
  public:
    Terminal(); // The default and only constructor
    void Print(const string); // The print function, params const string value
    void Print(const string, const int, const int); // The print function:
                                                    // params:
                                                    // const string value
                                                    // const int x
                                                    // const int y

    void CreateHierarchyChoice(const Tree *);   // Builds a hierarchy prompt
                                                // params:
                                                // const Tree *hierarchcy tree
    vector<string> Prompt();                    // Prompts the User for select
                                                // return:
                                                // vector<string> selected
  private:
    string writing_string;
    struct termios terminal_options;
    struct termios revert_options;
    int prompt_height;
    int terminal_height;
    vector<string> prompt_strings;
    vector<int> cursor_pos;
    vector<bool> prompt_selected;
};

#endif
