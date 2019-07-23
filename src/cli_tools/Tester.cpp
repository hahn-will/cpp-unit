#include <functional>
#include <iostream>
#include <ostream>
#include <sstream>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

void test_function(function<void(string)> exec) {
  exec("test");
}

int main() {
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
    putchar(c);
    c = getchar();
  }

  fflush(stdout);

  tcsetattr(STDOUT_FILENO, TCSANOW, &old_options);
  fflush(stdout);
}
