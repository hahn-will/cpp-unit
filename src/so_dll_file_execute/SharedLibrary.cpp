#include "SharedLibrary.hpp"
#include <dlfcn.h>
#include <stdexcept>

SharedLibrary::SharedLibrary(const char *file_name) {
  handle = dlopen(file_name, RTLD_LAZY);
  if (!handle)
    throw std::runtime_error(dlerror());
}

SharedLibrary::~SharedLibrary() {

}

void *SharedLibrary::Execute(const char *function_name) {
  char *error;
  void * (*func)();
  *(void**) (&func) = dlsym(handle, function_name);
  if ((error = dlerror()))
    throw std::runtime_error(error);

  return (void*)func();
}
