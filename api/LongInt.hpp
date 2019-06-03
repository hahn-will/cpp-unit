#ifndef LONGINT_HPP__
#define LONGINT_HPP__

#include <ostream>

#include "Object.hpp"

class LongInt : public Object {
  public:
    LongInt(long int value) : Object(), value(value) {}
    ~LongInt() {}

    // Assignment Operators
    template <typename T>
    LongInt& operator=(const T a) { value = a; return *this; }
    LongInt& operator=(const LongInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    LongInt& operator+=(const T a) { value += a; return *this; }
    LongInt& operator+=(const LongInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    LongInt& operator-=(const T a) { value -= a; return *this; }
    LongInt& operator-=(const LongInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    LongInt& operator*=(const T a) { value *= a; return *this; }
    LongInt& operator*=(const LongInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    LongInt& operator/=(const T a) { value /= a; return *this; }
    LongInt& operator/=(const LongInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    LongInt& operator%=(const T a) { value %= a; return *this; }
    LongInt& operator%=(const LongInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    LongInt& operator&=(const T a) { value &= a; return *this; }
    LongInt& operator&=(const LongInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    LongInt& operator|=(const T a) { value |= a; return *this; }
    LongInt& operator|=(const LongInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    LongInt& operator^=(const T a) { value ^= a; return *this; }
    LongInt& operator^=(const LongInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    LongInt& operator<<=(const T a) { value <<= a; return *this; }
    LongInt& operator<<=(const LongInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    LongInt& operator>>=(const T a) { value >>= a; return *this; }
    LongInt& operator>>=(const LongInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    LongInt& operator++() { ++value; return *this; }
    LongInt operator++(int) { long int temp = value; value++; return LongInt(temp); }
    LongInt& operator--() { --value; return *this; }
    LongInt operator--(int) { long int temp = value; value--; return LongInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const LongInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const LongInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    LongInt operator+() const { return LongInt(+value); }
    LongInt operator-() const { return LongInt(-value); }
    LongInt operator~() const { return LongInt(~value); }

    // Binary operators
    template <typename T>
    LongInt operator+(const T &b) const { return LongInt(value + b); }
    LongInt operator+(const LongInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    LongInt operator-(const T &b) const { return LongInt(value - b); }
    LongInt operator-(const LongInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    LongInt operator*(const T &b) const { return LongInt(value * b); }
    LongInt operator*(const LongInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    LongInt operator/(const T &b) const { return LongInt(value / b); }
    LongInt operator/(const LongInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    LongInt operator%(const T &b) const { return LongInt(value % b); }
    LongInt operator%(const LongInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    LongInt operator&(const T &b) const { return LongInt(value & b); }
    LongInt operator&(const LongInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    LongInt operator|(const T &b) const { return LongInt(value | b); }
    LongInt operator|(const LongInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    LongInt operator^(const T &b) const { return LongInt(value ^ b); }
    LongInt operator^(const LongInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    LongInt operator<<(const T &b) const { return LongInt(value << b); }
    LongInt operator<<(const LongInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    LongInt operator>>(const T &b) const { return LongInt(value >> b); }
    LongInt operator>>(const LongInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const LongInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const LongInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const LongInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const LongInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const LongInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const LongInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator long int() override { return value; }

    inline long int GetValue() const { return value; }
  private:
    long int value;
};

#endif
