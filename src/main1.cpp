#include <functional>
#include <iostream>

#include "pp_helpers.hpp"

TEST_SUITE(new_suite) {
  TEST_METHOD(m1, int a, char b, double c) {
    ASSERT_TRUE(1 == 2);
    std::cout << a << b << c << std::endl;
    return false;
  };

  TEST_CASE(m1, 3, 1, 'a', 53.1234);
}

int main() {
  SIMPLE_CPP_RUN(new_suite);
}
