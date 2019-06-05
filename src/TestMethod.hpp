#ifndef TEST_METHOD_HPP__
#define TEST_METHOD_HPP__

#include <vector>
#include <Object.hpp>
#include <utility>

class TestMethod {
  public:
    TestMethod(int num_params) : num_params(num_params) {}
    ~TestMethod();

    bool (*test_function)(...);
    void AddTestCase(Object **);
    void AddTestCaseDeleteFunction(void (*)(Object **, int), Object **);
    template<std::size_t N>
    void RunAllTestCases();
  private:
    std::vector<Object **> testCases;
    std::vector<void (*)(Object **, int)> delete_functions;
    int num_params;
    template<std::size_t... I>
    void unpack(Object **arr, std::index_sequence<I...>) { test_function(*(arr[I])...); }
    template<std::size_t N>
    void RunTestCase(Object **arr);
};

#endif
