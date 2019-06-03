#ifndef SHORTINT_HPP__
#define SHORTINT_HPP__

#include <ostream>

#include "Object.hpp"

class ShortInt : public Object {
  public:
    ShortInt(short int value) : Object(), value(value) {}
    ~ShortInt() {}

    // Assignment Operators
    template <typename T>
    ShortInt& operator=(const T a) { value = a; return *this; }
    ShortInt& operator=(const ShortInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    ShortInt& operator+=(const T a) { value += a; return *this; }
    ShortInt& operator+=(const ShortInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    ShortInt& operator-=(const T a) { value -= a; return *this; }
    ShortInt& operator-=(const ShortInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    ShortInt& operator*=(const T a) { value *= a; return *this; }
    ShortInt& operator*=(const ShortInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    ShortInt& operator/=(const T a) { value /= a; return *this; }
    ShortInt& operator/=(const ShortInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    ShortInt& operator%=(const T a) { value %= a; return *this; }
    ShortInt& operator%=(const ShortInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    ShortInt& operator&=(const T a) { value &= a; return *this; }
    ShortInt& operator&=(const ShortInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    ShortInt& operator|=(const T a) { value |= a; return *this; }
    ShortInt& operator|=(const ShortInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    ShortInt& operator^=(const T a) { value ^= a; return *this; }
    ShortInt& operator^=(const ShortInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    ShortInt& operator<<=(const T a) { value <<= a; return *this; }
    ShortInt& operator<<=(const ShortInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    ShortInt& operator>>=(const T a) { value >>= a; return *this; }
    ShortInt& operator>>=(const ShortInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    ShortInt& operator++() { ++value; return *this; }
    ShortInt operator++(int) { short int temp = value; value++; return ShortInt(temp); }
    ShortInt& operator--() { --value; return *this; }
    ShortInt operator--(int) { short int temp = value; value--; return ShortInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const ShortInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const ShortInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    ShortInt operator+() const { return ShortInt(+value); }
    ShortInt operator-() const { return ShortInt(-value); }
    ShortInt operator~() const { return ShortInt(~value); }

    // Binary operators
    template <typename T>
    ShortInt operator+(const T &b) const { return ShortInt(value + b); }
    ShortInt operator+(const ShortInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    ShortInt operator-(const T &b) const { return ShortInt(value - b); }
    ShortInt operator-(const ShortInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    ShortInt operator*(const T &b) const { return ShortInt(value * b); }
    ShortInt operator*(const ShortInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    ShortInt operator/(const T &b) const { return ShortInt(value / b); }
    ShortInt operator/(const ShortInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    ShortInt operator%(const T &b) const { return ShortInt(value % b); }
    ShortInt operator%(const ShortInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    ShortInt operator&(const T &b) const { return ShortInt(value & b); }
    ShortInt operator&(const ShortInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    ShortInt operator|(const T &b) const { return ShortInt(value | b); }
    ShortInt operator|(const ShortInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    ShortInt operator^(const T &b) const { return ShortInt(value ^ b); }
    ShortInt operator^(const ShortInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    ShortInt operator<<(const T &b) const { return ShortInt(value << b); }
    ShortInt operator<<(const ShortInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    ShortInt operator>>(const T &b) const { return ShortInt(value >> b); }
    ShortInt operator>>(const ShortInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const ShortInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const ShortInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const ShortInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const ShortInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const ShortInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const ShortInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator short int() override { return value; }

    inline short int GetValue() const { return value; }
  private:
    short int value;
};

#endif
