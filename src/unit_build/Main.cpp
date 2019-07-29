#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

#include "command_line/CommandLine.hpp"
#include "command_line/FunctionCaller.hpp"
//#include "utils/utils.hpp"

int main(int argc, char **argv) {
  CommandLine cl(argc, argv);

  if (!cl.ProcessArgs())
    return -1;

  FunctionCaller fc(cl.GetInputFiles());
  

  if (!cl.ProcessArgs())
    return errors::log(cl);

  void *handle;

  void (*func)();

  char *error;
  handle = dlopen(argv[1], RTLD_LAZY);
  if (!handle) {
    std::cerr << dlerror() << std::endl;
    return -1;
  }

  dlerror();

  *(void**) (&func) = dlsym(handle, argv[2]);

  if ((error = dlerror()) != NULL) {
    std::cerr << error << std::endl;
    return -1;
  }

  func();
}

// DESIRED FEATURES
// * Error Logging
// * automatically create a new makefile when necessary
// * generate a "ui" to access the files correctly
