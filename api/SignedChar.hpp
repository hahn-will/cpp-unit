#ifndef SIGNEDCHAR_HPP__
#define SIGNEDCHAR_HPP__

#include <ostream>

#include "Object.hpp"

class SignedChar : public Object {
  public:
    SignedChar(signed char value) : Object(), value(value) {}
    ~SignedChar() {}

    // Assignment Operators
    template <typename T>
    SignedChar& operator=(const T a) { value = a; return *this; }
    SignedChar& operator=(const SignedChar &b) { return operator=(b.GetValue()); }

    template <typename T>
    SignedChar& operator+=(const T a) { value += a; return *this; }
    SignedChar& operator+=(const SignedChar &b) { return operator+=(b.GetValue()); }

    template <typename T>
    SignedChar& operator-=(const T a) { value -= a; return *this; }
    SignedChar& operator-=(const SignedChar &b) { return operator-=(b.GetValue()); }

    template <typename T>
    SignedChar& operator*=(const T a) { value *= a; return *this; }
    SignedChar& operator*=(const SignedChar &b) { return operator*=(b.GetValue()); }

    template <typename T>
    SignedChar& operator/=(const T a) { value /= a; return *this; }
    SignedChar& operator/=(const SignedChar &b) { return operator/=(b.GetValue()); }

    template <typename T>
    SignedChar& operator%=(const T a) { value %= a; return *this; }
    SignedChar& operator%=(const SignedChar &b) { return operator%=(b.GetValue()); }

    template <typename T>
    SignedChar& operator&=(const T a) { value &= a; return *this; }
    SignedChar& operator&=(const SignedChar &b) { return operator&=(b.GetValue()); }

    template <typename T>
    SignedChar& operator|=(const T a) { value |= a; return *this; }
    SignedChar& operator|=(const SignedChar &b) { return operator|=(b.GetValue()); }

    template <typename T>
    SignedChar& operator^=(const T a) { value ^= a; return *this; }
    SignedChar& operator^=(const SignedChar &b) { return operator^=(b.GetValue()); }

    template <typename T>
    SignedChar& operator<<=(const T a) { value <<= a; return *this; }
    SignedChar& operator<<=(const SignedChar &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    SignedChar& operator>>=(const T a) { value >>= a; return *this; }
    SignedChar& operator>>=(const SignedChar &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    SignedChar& operator++() { ++value; return *this; }
    SignedChar operator++(int) { signed char temp = value; value++; return SignedChar(temp); }
    SignedChar& operator--() { --value; return *this; }
    SignedChar operator--(int) { signed char temp = value; value--; return SignedChar(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const SignedChar &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const SignedChar &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    SignedChar operator+() const { return SignedChar(+value); }
    SignedChar operator-() const { return SignedChar(-value); }
    SignedChar operator~() const { return SignedChar(~value); }

    // Binary operators
    template <typename T>
    SignedChar operator+(const T &b) const { return SignedChar(value + b); }
    SignedChar operator+(const SignedChar &b) const { return operator+(b.GetValue()); }

    template <typename T>
    SignedChar operator-(const T &b) const { return SignedChar(value - b); }
    SignedChar operator-(const SignedChar &b) const { return operator-(b.GetValue()); }

    template <typename T>
    SignedChar operator*(const T &b) const { return SignedChar(value * b); }
    SignedChar operator*(const SignedChar &b) const { return operator*(b.GetValue()); }

    template <typename T>
    SignedChar operator/(const T &b) const { return SignedChar(value / b); }
    SignedChar operator/(const SignedChar &b) const { return operator/(b.GetValue()); }

    template <typename T>
    SignedChar operator%(const T &b) const { return SignedChar(value % b); }
    SignedChar operator%(const SignedChar &b) const { return operator%(b.GetValue()); }

    template <typename T>
    SignedChar operator&(const T &b) const { return SignedChar(value & b); }
    SignedChar operator&(const SignedChar &b) const { return operator&(b.GetValue()); }

    template <typename T>
    SignedChar operator|(const T &b) const { return SignedChar(value | b); }
    SignedChar operator|(const SignedChar &b) const { return operator|(b.GetValue()); }

    template <typename T>
    SignedChar operator^(const T &b) const { return SignedChar(value ^ b); }
    SignedChar operator^(const SignedChar &b) const { return operator^(b.GetValue()); }

    template <typename T>
    SignedChar operator<<(const T &b) const { return SignedChar(value << b); }
    SignedChar operator<<(const SignedChar &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    SignedChar operator>>(const T &b) const { return SignedChar(value >> b); }
    SignedChar operator>>(const SignedChar &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const SignedChar &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const SignedChar &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const SignedChar &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const SignedChar &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const SignedChar &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const SignedChar &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator signed char() override { return value; }

    inline signed char GetValue() const { return value; }
  private:
    signed char value;
};

#endif
