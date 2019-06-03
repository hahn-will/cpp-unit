#ifndef UNSIGNEDCHAR_HPP__
#define UNSIGNEDCHAR_HPP__

#include <ostream>

#include "Object.hpp"

class UnsignedChar : public Object {
  public:
    UnsignedChar(unsigned char value) : Object(), value(value) {}
    ~UnsignedChar() {}

    // Assignment Operators
    template <typename T>
    UnsignedChar& operator=(const T a) { value = a; return *this; }
    UnsignedChar& operator=(const UnsignedChar &b) { return operator=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator+=(const T a) { value += a; return *this; }
    UnsignedChar& operator+=(const UnsignedChar &b) { return operator+=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator-=(const T a) { value -= a; return *this; }
    UnsignedChar& operator-=(const UnsignedChar &b) { return operator-=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator*=(const T a) { value *= a; return *this; }
    UnsignedChar& operator*=(const UnsignedChar &b) { return operator*=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator/=(const T a) { value /= a; return *this; }
    UnsignedChar& operator/=(const UnsignedChar &b) { return operator/=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator%=(const T a) { value %= a; return *this; }
    UnsignedChar& operator%=(const UnsignedChar &b) { return operator%=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator&=(const T a) { value &= a; return *this; }
    UnsignedChar& operator&=(const UnsignedChar &b) { return operator&=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator|=(const T a) { value |= a; return *this; }
    UnsignedChar& operator|=(const UnsignedChar &b) { return operator|=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator^=(const T a) { value ^= a; return *this; }
    UnsignedChar& operator^=(const UnsignedChar &b) { return operator^=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator<<=(const T a) { value <<= a; return *this; }
    UnsignedChar& operator<<=(const UnsignedChar &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    UnsignedChar& operator>>=(const T a) { value >>= a; return *this; }
    UnsignedChar& operator>>=(const UnsignedChar &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    UnsignedChar& operator++() { ++value; return *this; }
    UnsignedChar operator++(int) { unsigned char temp = value; value++; return UnsignedChar(temp); }
    UnsignedChar& operator--() { --value; return *this; }
    UnsignedChar operator--(int) { unsigned char temp = value; value--; return UnsignedChar(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const UnsignedChar &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const UnsignedChar &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    UnsignedChar operator+() const { return UnsignedChar(+value); }
    UnsignedChar operator-() const { return UnsignedChar(-value); }
    UnsignedChar operator~() const { return UnsignedChar(~value); }

    // Binary operators
    template <typename T>
    UnsignedChar operator+(const T &b) const { return UnsignedChar(value + b); }
    UnsignedChar operator+(const UnsignedChar &b) const { return operator+(b.GetValue()); }

    template <typename T>
    UnsignedChar operator-(const T &b) const { return UnsignedChar(value - b); }
    UnsignedChar operator-(const UnsignedChar &b) const { return operator-(b.GetValue()); }

    template <typename T>
    UnsignedChar operator*(const T &b) const { return UnsignedChar(value * b); }
    UnsignedChar operator*(const UnsignedChar &b) const { return operator*(b.GetValue()); }

    template <typename T>
    UnsignedChar operator/(const T &b) const { return UnsignedChar(value / b); }
    UnsignedChar operator/(const UnsignedChar &b) const { return operator/(b.GetValue()); }

    template <typename T>
    UnsignedChar operator%(const T &b) const { return UnsignedChar(value % b); }
    UnsignedChar operator%(const UnsignedChar &b) const { return operator%(b.GetValue()); }

    template <typename T>
    UnsignedChar operator&(const T &b) const { return UnsignedChar(value & b); }
    UnsignedChar operator&(const UnsignedChar &b) const { return operator&(b.GetValue()); }

    template <typename T>
    UnsignedChar operator|(const T &b) const { return UnsignedChar(value | b); }
    UnsignedChar operator|(const UnsignedChar &b) const { return operator|(b.GetValue()); }

    template <typename T>
    UnsignedChar operator^(const T &b) const { return UnsignedChar(value ^ b); }
    UnsignedChar operator^(const UnsignedChar &b) const { return operator^(b.GetValue()); }

    template <typename T>
    UnsignedChar operator<<(const T &b) const { return UnsignedChar(value << b); }
    UnsignedChar operator<<(const UnsignedChar &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    UnsignedChar operator>>(const T &b) const { return UnsignedChar(value >> b); }
    UnsignedChar operator>>(const UnsignedChar &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const UnsignedChar &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const UnsignedChar &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const UnsignedChar &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const UnsignedChar &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const UnsignedChar &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const UnsignedChar &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator unsigned char() override { return value; }

    inline unsigned char GetValue() const { return value; }
  private:
    unsigned char value;
};

#endif
