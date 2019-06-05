#ifndef PP_HELPERS_HPP__
#define PP_HELPERS_HPP__

#include "TestSuite.hpp"
#include <iostream>
#include <string>

#define SIMPLE_CPP_RUN(clname)\
  TestSuite clname##_tests = clname();

#define TEST_SUITE(t1) class t1 : public TestSuite {\
  public:\
    t1();\
};\
t1::t1() : TestSuite()

#define ASSERT_TRUE(assertion)\
  if (!assertion) {\
    exit = #assertion;\
    return false;\
  }

#define TEST_METHOD(m1, ...)\
  std::function<bool(std::string &, __VA_ARGS__)> m1 = [](std::string &exit, __VA_ARGS__) -> bool

#define TEST_CASE(m1, num_args, ...)\
  std::string name = #m1;\
  std::string args = #__VA_ARGS__;\
  std::string exit;\
  bool result = m1(exit, __VA_ARGS__);\
  process_result(name, args, exit, result);

#endif
