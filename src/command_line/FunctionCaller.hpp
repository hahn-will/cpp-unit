#ifndef FUNCTION_CALLER_HPP__
#define FUNCTION_CALLER_HPP__

#include <vector>
#include <string>
#include <map>
#include <functional>

#include "../utils/utils.hpp"

using namespace std;

class FunctionCaller {
  public:
    FunctionCaller(vector<string> *);
    FunctionCaller(vector<string> *, bool);
    ~FunctionCaller();

    void HandleTestCases();
  private:
    map<string, function<bool(TestLogger &)>> executables;
    bool save_report;
    vector<string> *files_to_compile;

    void BuildMakefile();
};

#endif
