#include "TestMethod.hpp"

TestMethod::TestMethod(int num_parameters) : num_parameters(num_parameters) {
}

TestMethod::~TestMethod() {
  for (unsigned i = 0; i < delete_functions.size(); i++) {
    delete_functions[i](testCases[i]);
  }
}

void TestMethod::AddTestCase(void * params) {
  AddTestCaseDeleteFunction(, params);
}

void TestMethod::AddTestCaseDeleteFunction(void (*func)(void *), void *params) {
  testCases.push_back(params);
  delete_functions.push_back(func);
}
