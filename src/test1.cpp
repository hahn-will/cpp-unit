#include "pp_helper.hpp"

TEST_SUITE(nsuite) {
  TEST_METHOD(test_test_method, 3, int a, signed char b, bool c) {
    a = 1, b = 'c', c = false;
    return true;
  };
}
