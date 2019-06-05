#ifndef TEST_SUITE_HPP__
#define TEST_SUITE_HPP__

#include <string>
#include <iostream>
#include <fstream>

class TestSuite {
  public:
    TestSuite();
    TestSuite(std::string);
    ~TestSuite();
    void process_result(std::string name,
                        std::string args,
                        std::string exit_details,
                        bool result);
    void SetOutputFileName(const std::string);
    void SetOutputFormat(const FileFormat *const);
  private:
    std::ostream output;
    std::string output_file_name;
    FileFormat *output_file_format;
};

#endif
