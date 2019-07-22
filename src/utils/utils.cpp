#include "utils.hpp"

#include <iostream>
#include <array>
#include <cstdio>
#include <memory>

using namespace std;

unsigned update_file_num(unsigned new_file_num) {
  static unsigned file_num = 0;

  unsigned temp = file_num;

  file_num = new_file_num;
  return temp;
}

int errors::log(ProcessHandler &ph) {
  std::cerr << ph.GetErrors() << std::endl;
  return 1;
}

std::string exec_to_string(const char *command) {

#define BUFFER_SIZE 128

  std::array<char, BUFFER_SIZE> buffer;
  std::string output;

  unique_ptr<FILE, decltype(&pclose)> pipe(popen(command, "r"), pclose);

  if (!pipe)
    throw runtime_error("popen failed");

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    output.append(buffer.data());
  }

  return output;
}
