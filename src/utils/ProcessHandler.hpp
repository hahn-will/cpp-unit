#ifndef PROCESS_HANDLER_HPP__
#define PROCESS_HANDLER_HPP__

#include <sstream>
#include <string>

class ProcessHandler {
  public:
    ProcessHandler();

    std::string GetErrors();

  protected:
    template<typename t>
    void log_error(t);

  private:
    std::stringstream errors;
};

#endif
