#ifndef UNSIGNEDINT_HPP__
#define UNSIGNEDINT_HPP__

#include <ostream>

#include "Object.hpp"

class UnsignedInt : public Object {
  public:
    UnsignedInt(unsigned int value) : Object(), value(value) {}
    ~UnsignedInt() {}

    // Assignment Operators
    template <typename T>
    UnsignedInt& operator=(const T a) { value = a; return *this; }
    UnsignedInt& operator=(const UnsignedInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator+=(const T a) { value += a; return *this; }
    UnsignedInt& operator+=(const UnsignedInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator-=(const T a) { value -= a; return *this; }
    UnsignedInt& operator-=(const UnsignedInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator*=(const T a) { value *= a; return *this; }
    UnsignedInt& operator*=(const UnsignedInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator/=(const T a) { value /= a; return *this; }
    UnsignedInt& operator/=(const UnsignedInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator%=(const T a) { value %= a; return *this; }
    UnsignedInt& operator%=(const UnsignedInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator&=(const T a) { value &= a; return *this; }
    UnsignedInt& operator&=(const UnsignedInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator|=(const T a) { value |= a; return *this; }
    UnsignedInt& operator|=(const UnsignedInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator^=(const T a) { value ^= a; return *this; }
    UnsignedInt& operator^=(const UnsignedInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator<<=(const T a) { value <<= a; return *this; }
    UnsignedInt& operator<<=(const UnsignedInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    UnsignedInt& operator>>=(const T a) { value >>= a; return *this; }
    UnsignedInt& operator>>=(const UnsignedInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    UnsignedInt& operator++() { ++value; return *this; }
    UnsignedInt operator++(int) { unsigned int temp = value; value++; return UnsignedInt(temp); }
    UnsignedInt& operator--() { --value; return *this; }
    UnsignedInt operator--(int) { unsigned int temp = value; value--; return UnsignedInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const UnsignedInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const UnsignedInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    UnsignedInt operator+() const { return UnsignedInt(+value); }
    UnsignedInt operator-() const { return UnsignedInt(-value); }
    UnsignedInt operator~() const { return UnsignedInt(~value); }

    // Binary operators
    template <typename T>
    UnsignedInt operator+(const T &b) const { return UnsignedInt(value + b); }
    UnsignedInt operator+(const UnsignedInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    UnsignedInt operator-(const T &b) const { return UnsignedInt(value - b); }
    UnsignedInt operator-(const UnsignedInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    UnsignedInt operator*(const T &b) const { return UnsignedInt(value * b); }
    UnsignedInt operator*(const UnsignedInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    UnsignedInt operator/(const T &b) const { return UnsignedInt(value / b); }
    UnsignedInt operator/(const UnsignedInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    UnsignedInt operator%(const T &b) const { return UnsignedInt(value % b); }
    UnsignedInt operator%(const UnsignedInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    UnsignedInt operator&(const T &b) const { return UnsignedInt(value & b); }
    UnsignedInt operator&(const UnsignedInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    UnsignedInt operator|(const T &b) const { return UnsignedInt(value | b); }
    UnsignedInt operator|(const UnsignedInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    UnsignedInt operator^(const T &b) const { return UnsignedInt(value ^ b); }
    UnsignedInt operator^(const UnsignedInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    UnsignedInt operator<<(const T &b) const { return UnsignedInt(value << b); }
    UnsignedInt operator<<(const UnsignedInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    UnsignedInt operator>>(const T &b) const { return UnsignedInt(value >> b); }
    UnsignedInt operator>>(const UnsignedInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const UnsignedInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const UnsignedInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const UnsignedInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const UnsignedInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const UnsignedInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const UnsignedInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator unsigned int() override { return value; }

    inline unsigned int GetValue() const { return value; }
  private:
    unsigned int value;
};

#endif
