#ifndef UNSIGNEDLONGLONGINT_HPP__
#define UNSIGNEDLONGLONGINT_HPP__

#include <ostream>

#include "Object.hpp"

class UnsignedLongLongInt : public Object {
  public:
    UnsignedLongLongInt(unsigned long long int value) : Object(), value(value) {}
    ~UnsignedLongLongInt() {}

    // Assignment Operators
    template <typename T>
    UnsignedLongLongInt& operator=(const T a) { value = a; return *this; }
    UnsignedLongLongInt& operator=(const UnsignedLongLongInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator+=(const T a) { value += a; return *this; }
    UnsignedLongLongInt& operator+=(const UnsignedLongLongInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator-=(const T a) { value -= a; return *this; }
    UnsignedLongLongInt& operator-=(const UnsignedLongLongInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator*=(const T a) { value *= a; return *this; }
    UnsignedLongLongInt& operator*=(const UnsignedLongLongInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator/=(const T a) { value /= a; return *this; }
    UnsignedLongLongInt& operator/=(const UnsignedLongLongInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator%=(const T a) { value %= a; return *this; }
    UnsignedLongLongInt& operator%=(const UnsignedLongLongInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator&=(const T a) { value &= a; return *this; }
    UnsignedLongLongInt& operator&=(const UnsignedLongLongInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator|=(const T a) { value |= a; return *this; }
    UnsignedLongLongInt& operator|=(const UnsignedLongLongInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator^=(const T a) { value ^= a; return *this; }
    UnsignedLongLongInt& operator^=(const UnsignedLongLongInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator<<=(const T a) { value <<= a; return *this; }
    UnsignedLongLongInt& operator<<=(const UnsignedLongLongInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt& operator>>=(const T a) { value >>= a; return *this; }
    UnsignedLongLongInt& operator>>=(const UnsignedLongLongInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    UnsignedLongLongInt& operator++() { ++value; return *this; }
    UnsignedLongLongInt operator++(int) { unsigned long long int temp = value; value++; return UnsignedLongLongInt(temp); }
    UnsignedLongLongInt& operator--() { --value; return *this; }
    UnsignedLongLongInt operator--(int) { unsigned long long int temp = value; value--; return UnsignedLongLongInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const UnsignedLongLongInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const UnsignedLongLongInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    UnsignedLongLongInt operator+() const { return UnsignedLongLongInt(+value); }
    UnsignedLongLongInt operator-() const { return UnsignedLongLongInt(-value); }
    UnsignedLongLongInt operator~() const { return UnsignedLongLongInt(~value); }

    // Binary operators
    template <typename T>
    UnsignedLongLongInt operator+(const T &b) const { return UnsignedLongLongInt(value + b); }
    UnsignedLongLongInt operator+(const UnsignedLongLongInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator-(const T &b) const { return UnsignedLongLongInt(value - b); }
    UnsignedLongLongInt operator-(const UnsignedLongLongInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator*(const T &b) const { return UnsignedLongLongInt(value * b); }
    UnsignedLongLongInt operator*(const UnsignedLongLongInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator/(const T &b) const { return UnsignedLongLongInt(value / b); }
    UnsignedLongLongInt operator/(const UnsignedLongLongInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator%(const T &b) const { return UnsignedLongLongInt(value % b); }
    UnsignedLongLongInt operator%(const UnsignedLongLongInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator&(const T &b) const { return UnsignedLongLongInt(value & b); }
    UnsignedLongLongInt operator&(const UnsignedLongLongInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator|(const T &b) const { return UnsignedLongLongInt(value | b); }
    UnsignedLongLongInt operator|(const UnsignedLongLongInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator^(const T &b) const { return UnsignedLongLongInt(value ^ b); }
    UnsignedLongLongInt operator^(const UnsignedLongLongInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator<<(const T &b) const { return UnsignedLongLongInt(value << b); }
    UnsignedLongLongInt operator<<(const UnsignedLongLongInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    UnsignedLongLongInt operator>>(const T &b) const { return UnsignedLongLongInt(value >> b); }
    UnsignedLongLongInt operator>>(const UnsignedLongLongInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const UnsignedLongLongInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const UnsignedLongLongInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const UnsignedLongLongInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const UnsignedLongLongInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const UnsignedLongLongInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const UnsignedLongLongInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator unsigned long long int() override { return value; }

    inline unsigned long long int GetValue() const { return value; }
  private:
    unsigned long long int value;
};

#endif
