#ifndef TEST_SUITE_HPP__
#define TEST_SUITE_HPP__

#include "TestMethod.hpp"

class TestSuite {
  public:
    TestSuite();
    ~TestSuite();
    void AddTestMethod(TestMethod *);
    void RunAllTests();
  private:
    std::vector<TestMethod *> test_methods;
};

#define TEST_SUITE(sn)\
  class sn : public TestSuite {\
    public:\
      sn();\
    private:\
  };\
  sn::sn() : TestSuite()

#define TEST_METHOD(tm, num_parameters)\
  TestMethod *tm = new TestMethod(num_paramters);\
  tm->test_function = [](void *parameters, int tm->num_parameters) -> bool

#endif
