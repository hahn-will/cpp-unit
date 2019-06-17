#ifndef PREPROCESSOR_HPP__
#define PREPROCESSOR_HPP__

#include <vector>
#include <string>

#include "utils.hpp"

namespace preprocessor {
  std::vector<std::string> process_all(int, char**, utils::flag_options &);
};

#endif /* PREPROCESSOR_HPP__ */
