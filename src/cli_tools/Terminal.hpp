#ifndef TERMINAL_HPP__
#define TERMINAL_HPP__

#include <string>
#include <ostream>
#include <array>

using namespace std;

class Terminal {
  public:
    Terminal(ostream &);
    void Print(const string);
    void Print(const string, const int, const int);

    void DrawMenu(Tree *);

  private:
};

#endif
