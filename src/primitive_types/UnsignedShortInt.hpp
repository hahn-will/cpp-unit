#ifndef UNSIGNEDSHORTINT_HPP__
#define UNSIGNEDSHORTINT_HPP__

#include <ostream>

#include "Object.hpp"

class UnsignedShortInt : public Object {
  public:
    UnsignedShortInt(unsigned short int value) : Object(), value(value) {}
    ~UnsignedShortInt() {}

    // Assignment Operators
    template <typename T>
    UnsignedShortInt& operator=(const T a) { value = a; return *this; }
    UnsignedShortInt& operator=(const UnsignedShortInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator+=(const T a) { value += a; return *this; }
    UnsignedShortInt& operator+=(const UnsignedShortInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator-=(const T a) { value -= a; return *this; }
    UnsignedShortInt& operator-=(const UnsignedShortInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator*=(const T a) { value *= a; return *this; }
    UnsignedShortInt& operator*=(const UnsignedShortInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator/=(const T a) { value /= a; return *this; }
    UnsignedShortInt& operator/=(const UnsignedShortInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator%=(const T a) { value %= a; return *this; }
    UnsignedShortInt& operator%=(const UnsignedShortInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator&=(const T a) { value &= a; return *this; }
    UnsignedShortInt& operator&=(const UnsignedShortInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator|=(const T a) { value |= a; return *this; }
    UnsignedShortInt& operator|=(const UnsignedShortInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator^=(const T a) { value ^= a; return *this; }
    UnsignedShortInt& operator^=(const UnsignedShortInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator<<=(const T a) { value <<= a; return *this; }
    UnsignedShortInt& operator<<=(const UnsignedShortInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    UnsignedShortInt& operator>>=(const T a) { value >>= a; return *this; }
    UnsignedShortInt& operator>>=(const UnsignedShortInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    UnsignedShortInt& operator++() { ++value; return *this; }
    UnsignedShortInt operator++(int) { unsigned short int temp = value; value++; return UnsignedShortInt(temp); }
    UnsignedShortInt& operator--() { --value; return *this; }
    UnsignedShortInt operator--(int) { unsigned short int temp = value; value--; return UnsignedShortInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const UnsignedShortInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const UnsignedShortInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    UnsignedShortInt operator+() const { return UnsignedShortInt(+value); }
    UnsignedShortInt operator-() const { return UnsignedShortInt(-value); }
    UnsignedShortInt operator~() const { return UnsignedShortInt(~value); }

    // Binary operators
    template <typename T>
    UnsignedShortInt operator+(const T &b) const { return UnsignedShortInt(value + b); }
    UnsignedShortInt operator+(const UnsignedShortInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator-(const T &b) const { return UnsignedShortInt(value - b); }
    UnsignedShortInt operator-(const UnsignedShortInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator*(const T &b) const { return UnsignedShortInt(value * b); }
    UnsignedShortInt operator*(const UnsignedShortInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator/(const T &b) const { return UnsignedShortInt(value / b); }
    UnsignedShortInt operator/(const UnsignedShortInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator%(const T &b) const { return UnsignedShortInt(value % b); }
    UnsignedShortInt operator%(const UnsignedShortInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator&(const T &b) const { return UnsignedShortInt(value & b); }
    UnsignedShortInt operator&(const UnsignedShortInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator|(const T &b) const { return UnsignedShortInt(value | b); }
    UnsignedShortInt operator|(const UnsignedShortInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator^(const T &b) const { return UnsignedShortInt(value ^ b); }
    UnsignedShortInt operator^(const UnsignedShortInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator<<(const T &b) const { return UnsignedShortInt(value << b); }
    UnsignedShortInt operator<<(const UnsignedShortInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    UnsignedShortInt operator>>(const T &b) const { return UnsignedShortInt(value >> b); }
    UnsignedShortInt operator>>(const UnsignedShortInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const UnsignedShortInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const UnsignedShortInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const UnsignedShortInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const UnsignedShortInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const UnsignedShortInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const UnsignedShortInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator unsigned short int() override { return value; }

    inline unsigned short int GetValue() const { return value; }
  private:
    unsigned short int value;
};

#endif
