#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "../src/utils.hpp"

using namespace std;

unsigned random_num(unsigned size) {
  return rand() % size + 1;
}

std::string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

string random_string() {
  return (random_string(random_num(256)));
}

string generate_method_signature() {
  stringstream ss;
  ss << random_string();
  unsigned sp = random_num(128);
  for (unsigned i = 0; i < sp; i++) {
    ss << " ";
  }
  ss << random_string();
  unsigned num_namespaces = random_num(32);
  for (unsigned i = 0; i < num_namespaces; i++) {
    sp = random_num(128) - 1;
    for (unsigned j = 0; j < sp; j++) {
      ss << " ";
    }
    ss << "::";
    sp = random_num(128) - 1;
    for (unsigned j = 0; j < sp; j++) {
      ss << " ";
    }
    ss << random_string();
  }
  ss << "(";
  if (random_num(2) - 1) {
    ss << random_string();
    unsigned num = random_num(32);
    for (unsigned i = 0; i < num; i++) {
      ss << "," << random_string();
    }
  }
  ss << ")" << (random_num(2) - 1 ? ";" : "{");
  return ss.str();
}

int percentage(int a, int b) {
  double p = (double)a/((double)b) * 100;
  return p;
}

int main() {
  srand(time(NULL));
  bool failed = false;
  for (int i = 0; i < 32768; i++) {
    if (utils::match_method_signature(generate_method_signature())) {
      cout << setfill('0') << "{" << setw(2) << percentage(i, 32767) << "%}" << "[" << setw(5) << i << " of " << 32767 << "] passed\r";
    }
    else {
      cerr << setfill('0') << "{" << setw(2) << percentage(i, 32767) << "%}" << "[" << setw(5) << i << " of " << 32767 << "] failed" << endl;
      failed = true;
    }
  }
  if (failed) {
    cout << "failed match_method_signature test cases" << endl;
  }
  else {
    cout << "passed match_method_signature test cases" << endl;
  }
}
