#ifndef SHARED_LIBRARY_HPP__
#define SHARED_LIBRARY_HPP__

class SharedLibrary {
  public:
    SharedLibrary(const char *);
    ~SharedLibrary();
    void Execute(const char *);
  private:
    void *handle;
};

#endif
