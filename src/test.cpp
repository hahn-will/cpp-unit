#include <iostream>

#include <Integer.hpp>

using namespace std;

int main() {
  Object **arr = new Object*[15];
  for (int i = 0 ; i < 15; i++) {
    arr[i] = new Integer(1);
  }

  for (int i = 0; i < 15; i++) {
    delete arr[i];
  }

  delete[]arr;
}
