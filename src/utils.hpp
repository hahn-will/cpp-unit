#include <stdlib.h>
#include <string>
#include <vector>

#define RED "\033[1;31m"
#define RESET "\033[0m"

namespace utils {

  typedef struct {
    std::string output_filename;
    std::string output_directory;
    std::vector<std::string> library_path;
    std::vector<std::string> library_name;
    std::string error;
  } flag_options;

  time_t since_creation(const std::string &);

  bool been_compiled(const std::string, const std::string);

  bool file_exists(const std::string &);

  std::string aggregate(const std::vector<std::string> &);

  bool check_directory(const std::string &);
};
