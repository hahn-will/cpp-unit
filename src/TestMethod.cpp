#include "TestMethod.hpp"

TestMethod::~TestMethod() {
  while (!testCases.empty()) {
    delete_functions.back()(testCases.back(), num_params);
    testCases.pop_back();
    delete_functions.pop_back();
  }
}

void delete_arr_wrapper(Object **arr, int num_params) {
  for (int i = 0; i < num_params; i++) {
    delete arr[i];
  }

  delete[] (arr);
}
void TestMethod::AddTestCase(Object **arr) {
  AddTestCaseDeleteFunction(delete_arr_wrapper, arr);
}

void TestMethod::AddTestCaseDeleteFunction(void (*func)(Object **, int),
                                              Object **arr) {
  testCases.push_back(arr);
  delete_functions.push_back(func);

}

template<std::size_t N>
void TestMethod::RunAllTestCases() {
  for (unsigned i = 0; i < testCases.size(); i++) {
    RunTestCase<N>(testCases[i]);
  }
}

template<std::size_t N>
void TestMethod::RunTestCase(Object **arr) {
  unpack(arr, std::make_index_sequence<N> {});
}
