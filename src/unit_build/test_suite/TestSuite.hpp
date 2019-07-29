#ifndef TEST_SUITE_HPP__
#define TEST_SUITE_HPP__

#include "../macros/pp_helpers.hpp"

#define INIT_TEST_SUITE

#define TEST_SUITE_SIGNATURE_HELPER(num) extern "C" {\
  void register_suite_number() \
  { update_file_num(num); } } TestSuiteResults\
  *GLUE(test_suite_, num) (TestSuite *suite)

#define TEST_SUITE_SIGNATURE TEST_SUITE_SIGNATURE_HELPER(__COUNTER__)

#define REGISTER_NEW_TEST_SUITE() TEST_SUITE_SIGNATURE

class TestSuite {
  public:
    TestSuite();
    ~TestSuite();

  private:

};

class TestSuiteResults {
  public:
    TestSuiteResults();
    ~TestSuiteResults();

  private:

};

#define TEST_SUITE REGISTER_NEW_TEST_SUITE()

#endif
