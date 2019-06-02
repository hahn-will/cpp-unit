#ifndef INTEGER_HPP__
#define INTEGER_HPP__

#include <ostream>

#include "Object.hpp"

class Integer : public Object {
  public:
    Integer(int);
    ~Integer();

    // Assignment Operators
    Integer& operator=(const int);
    Integer& operator=(const Integer &);
    Integer& operator+=(Integer);

    //Comparison Operators
    bool operator<(const int);
    bool operator<(const Integer&);
    bool operator>(const int);
    bool operator>(const Integer&);
    bool operator==(const int);
    bool operator==(const Integer&);
    bool operator!=(const int);
    bool operator!=(const Integer&);
    bool operator<=(const int);
    bool operator<=(const Integer&);
    bool operator>=(const int);
    bool operator>=(const Integer&);



    std::ostream& operator<<(std::ostream &os) {os << value; return os;};
    operator int();
        
    inline int GetValue() const { return value; };
  private:
    int value;
};

// binary operator overloads
// Addition operator overloads
Integer operator+(Integer, const Integer&);
Integer operator+(Integer, const int);
Integer operator+(int, const Integer&);

// subtraction operator overloads
Integer operator-(Integer, const Integer&);
Integer operator-(Integer, const int);
Integer operator-(int, const Integer&);

// multiplication operator overloads
Integer operator*(Integer, const Integer&);
Integer operator*(Integer, const int);
Integer operator*(int, const Integer&);

// division operator overloads
Integer operator/(Integer, const Integer&);
Integer operator/(Integer, const int);
Integer operator/(int, const Integer&);

// modulo operator overloads
Integer operator%(Integer, const Integer&);
Integer operator%(Integer, const int);
Integer operator%(int, const Integer&);

// bitwize-and operator overload
Integer operator&(Integer, const Integer&);
Integer operator&(Integer, const int);
Integer operator&(int, const Integer&);

// bitwize-or operator overload
Integer operator|(Integer, const Integer&);
Integer operator|(Integer, const int);
Integer operator|(int, const Integer&);

// bitwize-xor operator overload
Integer operator^(Integer, const Integer&);
Integer operator^(Integer, const int);
Integer operator^(int, const Integer&);

// bitwize-left shift operator overload
Integer operator<<(Integer, const Integer&);
Integer operator<<(Integer, const int);
Integer operator<<(int, const Integer&);

// bitwize-right shift operator overload
Integer operator>>(Integer, const Integer&);
Integer operator>>(Integer, const int);
Integer operator>>(int, const Integer&);

#endif
