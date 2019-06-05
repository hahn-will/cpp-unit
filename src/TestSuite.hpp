#ifndef TEST_SUITE_HPP__
#define TEST_SUITE_HPP__

#include <string>
#include <iostream>

class TestSuite {
  public:
    TestSuite() {}
    ~TestSuite() {}
    void process_result(std::string name,
                        std::string args,
                        std::string exit_details,
                        bool result);
  private:
};

void TestSuite::process_result(std::string name,
                          std::string args,
                          std::string exit,
                          bool result) {
  std::cout << name << " " << (result ? "passed " : "failed on assertion ") << exit << " with arguments " << args << std::endl;
}

#endif
