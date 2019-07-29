#include "ProcessHandler.hpp"

ProcessHandler::ProcessHandler() {

}

template<typename t>
void ProcessHandler::log_error(t type) {
  errors << type << std::endl;
}

std::string ProcessHandler::GetErrors() {
  return errors.str();
}
