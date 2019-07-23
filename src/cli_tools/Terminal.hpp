#ifndef TERMINAL_HPP__
#define TERMINAL_HPP__

#include "Tree.hpp"

#include <string>

using namespace std;

class Terminal {
  public:
    Terminal();
    void Print(const string);
    void Print(const string, const int, const int);

    void CreateHierarchyChoice(const Tree *);
    void Prompt();
  private:
    string writing_string;
};

#endif
