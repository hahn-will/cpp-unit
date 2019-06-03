#ifndef UNSIGNEDLONGINT_HPP__
#define UNSIGNEDLONGINT_HPP__

#include <ostream>

#include "Object.hpp"

class UnsignedLongInt : public Object {
  public:
    UnsignedLongInt(unsigned long int value) : Object(), value(value) {}
    ~UnsignedLongInt() {}

    // Assignment Operators
    template <typename T>
    UnsignedLongInt& operator=(const T a) { value = a; return *this; }
    UnsignedLongInt& operator=(const UnsignedLongInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator+=(const T a) { value += a; return *this; }
    UnsignedLongInt& operator+=(const UnsignedLongInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator-=(const T a) { value -= a; return *this; }
    UnsignedLongInt& operator-=(const UnsignedLongInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator*=(const T a) { value *= a; return *this; }
    UnsignedLongInt& operator*=(const UnsignedLongInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator/=(const T a) { value /= a; return *this; }
    UnsignedLongInt& operator/=(const UnsignedLongInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator%=(const T a) { value %= a; return *this; }
    UnsignedLongInt& operator%=(const UnsignedLongInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator&=(const T a) { value &= a; return *this; }
    UnsignedLongInt& operator&=(const UnsignedLongInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator|=(const T a) { value |= a; return *this; }
    UnsignedLongInt& operator|=(const UnsignedLongInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator^=(const T a) { value ^= a; return *this; }
    UnsignedLongInt& operator^=(const UnsignedLongInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator<<=(const T a) { value <<= a; return *this; }
    UnsignedLongInt& operator<<=(const UnsignedLongInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    UnsignedLongInt& operator>>=(const T a) { value >>= a; return *this; }
    UnsignedLongInt& operator>>=(const UnsignedLongInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    UnsignedLongInt& operator++() { ++value; return *this; }
    UnsignedLongInt operator++(int) { unsigned long int temp = value; value++; return UnsignedLongInt(temp); }
    UnsignedLongInt& operator--() { --value; return *this; }
    UnsignedLongInt operator--(int) { unsigned long int temp = value; value--; return UnsignedLongInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const UnsignedLongInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const UnsignedLongInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    UnsignedLongInt operator+() const { return UnsignedLongInt(+value); }
    UnsignedLongInt operator-() const { return UnsignedLongInt(-value); }
    UnsignedLongInt operator~() const { return UnsignedLongInt(~value); }

    // Binary operators
    template <typename T>
    UnsignedLongInt operator+(const T &b) const { return UnsignedLongInt(value + b); }
    UnsignedLongInt operator+(const UnsignedLongInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator-(const T &b) const { return UnsignedLongInt(value - b); }
    UnsignedLongInt operator-(const UnsignedLongInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator*(const T &b) const { return UnsignedLongInt(value * b); }
    UnsignedLongInt operator*(const UnsignedLongInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator/(const T &b) const { return UnsignedLongInt(value / b); }
    UnsignedLongInt operator/(const UnsignedLongInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator%(const T &b) const { return UnsignedLongInt(value % b); }
    UnsignedLongInt operator%(const UnsignedLongInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator&(const T &b) const { return UnsignedLongInt(value & b); }
    UnsignedLongInt operator&(const UnsignedLongInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator|(const T &b) const { return UnsignedLongInt(value | b); }
    UnsignedLongInt operator|(const UnsignedLongInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator^(const T &b) const { return UnsignedLongInt(value ^ b); }
    UnsignedLongInt operator^(const UnsignedLongInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator<<(const T &b) const { return UnsignedLongInt(value << b); }
    UnsignedLongInt operator<<(const UnsignedLongInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    UnsignedLongInt operator>>(const T &b) const { return UnsignedLongInt(value >> b); }
    UnsignedLongInt operator>>(const UnsignedLongInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const UnsignedLongInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const UnsignedLongInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const UnsignedLongInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const UnsignedLongInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const UnsignedLongInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const UnsignedLongInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator unsigned long int() override { return value; }

    inline unsigned long int GetValue() const { return value; }
  private:
    unsigned long int value;
};

#endif
