#include <iostream>
#include <cstdlib>
#include <dlfcn.h>

int main(int argc, char **argv) {
  if (argc < 3)
    return -1;
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
