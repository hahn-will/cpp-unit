#ifndef PP_HELPER_HPP__
#define PP_HELPER_HPP__

#include "TestSuite.hpp"

#define TEST_SUITE(test_suite_name) \
  class test_suite_name : TestSuite { \
    public: \
      test_suite_name(); \
  };\
  test_suite_name::test_suite_name() : TestSuite()

#define TEST_METHOD(test_method_name, num_args, ...)\
  TestMethod *test_method_name = new TestMethod(num_args);\
  constexpr size_t N##test_method_name = num_args;\
  test_method_name->test_function = [](__VA_ARGS__) -> bool 

#define TEST_CASE(test_method_name, arr)

#define START_TEST_CASES(test_method_name)

#define END_TEST_CASES(test_method_name)

#define RUN_TEST_SUITE(test_suite_name)\

#endif
