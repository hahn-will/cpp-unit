#ifndef TEST_METHOD_HPP__
#define TEST_METHOD_HPP__

#include <vector>

class TestMethod {
  public:
    TestMethod(int);
    ~TestMethod();
    bool (*test_function)(void *);
    void AddTestCase(void *);
    void AddTestCaseDeleteFunction(void (*)(void *), void *);
    void RunAllTestCases();
  private:
    std::vector<void *> testCases;
    std::vector<void (*)(void *)> delete_functions;
    int num_parameters;
};

#define TEST_CASE(tm, params)\
  tm->AddTestCase(params);

#define TEST_CASE_DELETE(tm, params, del_func)\
  tm->AddTestCaseDeleteFunction(params, del_func);

#endif
