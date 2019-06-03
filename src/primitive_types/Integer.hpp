#ifndef INTEGER_HPP__
#define INTEGER_HPP__

#include <ostream>

#include "Object.hpp"

class Integer : public Object {
  public:
    Integer(int value) : Object(), value(value) {};
    ~Integer() {};

    // Assignment Operators
    template<typename T>
    Integer& operator=(const T new_value) { value = new_value; return *this; };
    Integer& operator=(const Integer &nv) { return operator=(nv.GetValue()); };

    template<typename T>
    Integer& operator+=(const T a) { value += a; return *this; };
    Integer& operator+=(const Integer &b) { return operator+=(b.GetValue()); };

    template<typename T>
    Integer& operator-=(const T a) { value -= a; return *this; };
    Integer& operator-=(const Integer &b) { return operator-=(b.GetValue()); };

    template<typename T>
    Integer& operator*=(const T a) { value *= a; return *this; };
    Integer& operator*=(const Integer &b) { return operator*=(b.GetValue()); };

    template<typename T>
    Integer& operator/=(const T a) { value /= a; return *this; };
    Integer& operator/=(const Integer &b) { return operator/=(b.GetValue()); };

    template<typename T>
    Integer& operator%=(const T a) { value %= a; return *this; };
    Integer& operator%=(const Integer &b) { return operator%=(b.GetValue()); };

    template<typename T>
    Integer& operator&=(const T a) { value &= a; return *this; };
    Integer& operator&=(const Integer &b) { return operator&=(b.GetValue()); };

    template<typename T>
    Integer& operator|=(const T a) { value |= a; return *this; };
    Integer& operator|=(const Integer &b) { return operator|=(b.GetValue()); };

    template<typename T>
    Integer& operator^=(const T a) { value ^= a; return *this; };
    Integer& operator^=(const Integer &b) { return operator^=(b.GetValue()); };

    template<typename T>
    Integer& operator<<=(const T a) { value <<= a; return *this; };
    Integer& operator<<=(const Integer &b) { return operator<<=(b.GetValue()); };

    template<typename T>
    Integer& operator>>=(const T a) { value >>= a; return *this; };
    Integer& operator>>=(const Integer &b) { return operator>>=(b.GetValue()); };

    // Increment Decrement operators
    Integer& operator++() { ++value; return *this; };
    Integer operator++(int temp) { temp = value; value++; return Integer(temp); };
    Integer& operator--() { --value; return *this; };
    Integer operator--(int temp) { temp = value; value--; return Integer(temp); };

    // Logical operators
    bool operator!() const { return !value; };

    template<typename T>
    bool operator&&(const T &b) const { return value && b; };
    bool operator&&(const Integer &b) const { return operator&&(b.GetValue()); };

    template<typename T>
    bool operator||(const T &b) const { return value || b; };
    bool operator||(const Integer &b) const { return operator||(b.GetValue()); };

    // Arithmetic Operators
    // Unary operators
    Integer operator+() const { return Integer(+value); };
    Integer operator-() const { return Integer(-value); };
    Integer operator~() const { return Integer(~value); };

    // Binary operators
    template<typename T>
    Integer operator+(const T &b) const { return Integer(value + b); };
    Integer operator+(const Integer &b) const { return operator+(b.GetValue()); }

    template<typename T>
    Integer operator-(const T &b) const { return Integer(value - b); };
    Integer operator-(const Integer &b) const { return operator-(b.GetValue()); };

    template <typename T>
    Integer operator*(const T &b) const { return Integer(value * b); };
    Integer operator*(const Integer &b) const { return operator*(b.GetValue()); };

    template <typename T>
    Integer operator/(const T &b) const { return Integer(value / b); };
    Integer operator/(const Integer &b) const { return operator/(b.GetValue()); };

    template <typename T>
    Integer operator%(const T &b) const { return Integer(value % b); };
    Integer operator%(const Integer &b) const { return operator%(b.GetValue()); };

    template <typename T>
    Integer operator&(const T &b) const { return Integer(value & b); };
    Integer operator&(const Integer &b) const { return operator&(b.GetValue()); };

    template <typename T>
    Integer operator|(const T &b) const { return Integer(value | b); };
    Integer operator|(const Integer &b) const { return operator|(b.GetValue()); };

    template <typename T>
    Integer operator^(const T &b) const { return Integer(value ^ b); };
    Integer operator^(const Integer &b) const { return operator^(b.GetValue()); };

    template <typename T>
    Integer operator<<(const T &b) const { return Integer(value << b); };
    Integer operator<<(const Integer &b) const { return operator<<(b.GetValue()); };

    template <typename T>
    Integer operator>>(const T &b) const { return Integer(value >> b); };
    Integer operator>>(const Integer &b) const { return operator>>(b.GetValue()); };

    //Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; };
    bool operator==(const Integer &b) const { return operator==(b.GetValue()); };

    template <typename T>
    bool operator!=(const T &b) const { return value != b; };
    bool operator!=(const Integer &b) const { return operator!=(b.GetValue()); };

    template <typename T>
    bool operator<(const T &b) const { return value < b; };
    bool operator<(const Integer &b) const { return operator<(b.GetValue()); };

    template <typename T>
    bool operator>(const T &b) const { return value > b; };
    bool operator>(const Integer &b) const { return operator>(b.GetValue()); };

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; };
    bool operator<=(const Integer &b) const { return operator<=(b.GetValue()); };

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; };
    bool operator>=(const Integer &b) const { return operator>=(b.GetValue()); };

    std::ostream& operator<<(std::ostream &os) {os << value; return os;};

    operator int() { return value; };
        
    inline int GetValue() const { return value; };
  private:
    int value;
};

#endif
