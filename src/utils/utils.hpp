#ifndef UTILS_HPP__
#define UTILS_HPP__

#include "ProcessHandler.hpp"

unsigned update_file_num(unsigned);

namespace errors {
  int log(ProcessHandler &);
};

class TestLogger {
  public:
    TestLogger();
  private:
};

#endif
