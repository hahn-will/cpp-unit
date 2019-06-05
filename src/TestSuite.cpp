#include "TestSuite.hpp"

TestSuite::TestSuite() : output(NULL) {
  std::streambuf *strbuf = std::cout.rdbuf();
  output.rdbuf(strbuf);
}

TestSuite::TestSuite(std::string file_name) : TestSuite() {
  std::streambuf *strbuf;
  std::ofstream of(file_name);
  strbuf = of.rdbuf();
  output.rdbuf(strbuf);
  SetOutputFileName(file_name);
}

TestSuite::~TestSuite() {

}

void TestSuite::process_result(std::string name,
                          std::string args,
                          std::string exit,
                          bool result) {
  std::cout << name << " " << (result ? "passed " : "failed on assertion ") << exit << " with arguments " << args << std::endl;
}

void TestSuite::SetOutputFileName(const std::string file_name) {
  output_file_name = file_name;
}

void TestSuite::SetOutputFormat(const FileFormat *const file_format) {
  output_file_format = file_format;
}
