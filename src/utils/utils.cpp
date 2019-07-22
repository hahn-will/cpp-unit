#include "utils.hpp"

#include <iostream>

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
