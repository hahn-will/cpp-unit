#ifndef OBJECT_HPP__
#define OBJECT_HPP__

#define INT_DEFAULT (0)
#define DOUBLE_DEFAULT (0.0)
#define FLOAT_DEFAULT (0.0f)
#define CHAR_DEFAULT ('\0')
#define LONG_DEFAULT (0L)
#define UNSIGNED_DEFAULT (0U)
#define BOOL_DEFAULT (false)



class Object {
  public:
    Object() {};
    virtual ~Object() {};
    virtual operator short int() { return INT_DEFAULT; }
    virtual operator unsigned short int() { return INT_DEFAULT; }
    virtual operator unsigned int() { return INT_DEFAULT; }
    virtual operator int() { return INT_DEFAULT; }
    virtual operator long int() { return INT_DEFAULT; }
    virtual operator unsigned long int() { return INT_DEFAULT; }
    virtual operator long long int() { return INT_DEFAULT; }
    virtual operator unsigned long long int() { return INT_DEFAULT; }
    virtual operator signed char() { return CHAR_DEFAULT; }
    virtual operator unsigned char() {return CHAR_DEFAULT; }
    virtual operator float() { return FLOAT_DEFAULT; }
    virtual operator double() { return DOUBLE_DEFAULT; }
    virtual operator long double() { return DOUBLE_DEFAULT; }
    virtual operator bool() { return BOOL_DEFAULT; }
    virtual operator wchar_t() { return CHAR_DEFAULT; }
  protected:
  private:
};

#endif
