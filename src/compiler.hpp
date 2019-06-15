#ifndef COMPILER_HPP__
#define COMPILER_HPP__

#include <vector>
#include <string>

namespace compiler {
  std::string compile_all(std::vector<std::string> &,
                          const std::string &,
                          const std::string &);
};

#endif /* COMPILER_HPP__ */
