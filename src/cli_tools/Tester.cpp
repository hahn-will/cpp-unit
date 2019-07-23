#include <functional>
#include <iostream>
#include <ostream>
#include <sstream>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Terminal.hpp"

using namespace std;

void test_function(function<void(string)> exec) {
  exec("test");
}

int main() {
  Terminal t;
  Tree *new_node = new Tree("asdf");
  Tree *root = new_node->AddSibling(new Tree("basdf"));
  new_node->AddChild(new Tree("Test"));

  t.CreateHierarchyChoice(root);

  t.Prompt();

  delete (root);
}

/*int main() {
  cout << "a" << endl;
  cout << "b" << endl;

  struct termios options  = {  };
  struct termios old_options;

  if (tcgetattr(STDOUT_FILENO, &old_options) < 0)
    return -1;

  memcpy(&options, &old_options, sizeof(struct termios));

  cfmakeraw(&options);
  fflush(stdout);

  tcsetattr(STDOUT_FILENO,TCSANOW, &options);

  char c = getchar();

  while (c != ':') {
    if (c == '\015' || c == '\012') {
      cout << "enter pressed" << endl;
      cout.flush();
    }
    putchar(c);
    c = getchar();
    
  }

  fflush(stdout);

  tcsetattr(STDOUT_FILENO, TCSANOW, &old_options);
  fflush(stdout);
}*/
