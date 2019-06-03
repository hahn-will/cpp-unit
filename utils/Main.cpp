#include <iostream>

#include "Integer.hpp"

using namespace std;

int main() {
  Integer *i = new Integer(34);
  Object *o = i;
  int a = *o;
  cout << a << endl;
}
