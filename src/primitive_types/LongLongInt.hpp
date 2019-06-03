#ifndef LONGLONGINT_HPP__
#define LONGLONGINT_HPP__

#include <ostream>

#include "Object.hpp"

class LongLongInt : public Object {
  public:
    LongLongInt(long long int value) : Object(), value(value) {}
    ~LongLongInt() {}

    // Assignment Operators
    template <typename T>
    LongLongInt& operator=(const T a) { value = a; return *this; }
    LongLongInt& operator=(const LongLongInt &b) { return operator=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator+=(const T a) { value += a; return *this; }
    LongLongInt& operator+=(const LongLongInt &b) { return operator+=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator-=(const T a) { value -= a; return *this; }
    LongLongInt& operator-=(const LongLongInt &b) { return operator-=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator*=(const T a) { value *= a; return *this; }
    LongLongInt& operator*=(const LongLongInt &b) { return operator*=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator/=(const T a) { value /= a; return *this; }
    LongLongInt& operator/=(const LongLongInt &b) { return operator/=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator%=(const T a) { value %= a; return *this; }
    LongLongInt& operator%=(const LongLongInt &b) { return operator%=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator&=(const T a) { value &= a; return *this; }
    LongLongInt& operator&=(const LongLongInt &b) { return operator&=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator|=(const T a) { value |= a; return *this; }
    LongLongInt& operator|=(const LongLongInt &b) { return operator|=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator^=(const T a) { value ^= a; return *this; }
    LongLongInt& operator^=(const LongLongInt &b) { return operator^=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator<<=(const T a) { value <<= a; return *this; }
    LongLongInt& operator<<=(const LongLongInt &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    LongLongInt& operator>>=(const T a) { value >>= a; return *this; }
    LongLongInt& operator>>=(const LongLongInt &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    LongLongInt& operator++() { ++value; return *this; }
    LongLongInt operator++(int) { long long int temp = value; value++; return LongLongInt(temp); }
    LongLongInt& operator--() { --value; return *this; }
    LongLongInt operator--(int) { long long int temp = value; value--; return LongLongInt(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const LongLongInt &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const LongLongInt &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    LongLongInt operator+() const { return LongLongInt(+value); }
    LongLongInt operator-() const { return LongLongInt(-value); }
    LongLongInt operator~() const { return LongLongInt(~value); }

    // Binary operators
    template <typename T>
    LongLongInt operator+(const T &b) const { return LongLongInt(value + b); }
    LongLongInt operator+(const LongLongInt &b) const { return operator+(b.GetValue()); }

    template <typename T>
    LongLongInt operator-(const T &b) const { return LongLongInt(value - b); }
    LongLongInt operator-(const LongLongInt &b) const { return operator-(b.GetValue()); }

    template <typename T>
    LongLongInt operator*(const T &b) const { return LongLongInt(value * b); }
    LongLongInt operator*(const LongLongInt &b) const { return operator*(b.GetValue()); }

    template <typename T>
    LongLongInt operator/(const T &b) const { return LongLongInt(value / b); }
    LongLongInt operator/(const LongLongInt &b) const { return operator/(b.GetValue()); }

    template <typename T>
    LongLongInt operator%(const T &b) const { return LongLongInt(value % b); }
    LongLongInt operator%(const LongLongInt &b) const { return operator%(b.GetValue()); }

    template <typename T>
    LongLongInt operator&(const T &b) const { return LongLongInt(value & b); }
    LongLongInt operator&(const LongLongInt &b) const { return operator&(b.GetValue()); }

    template <typename T>
    LongLongInt operator|(const T &b) const { return LongLongInt(value | b); }
    LongLongInt operator|(const LongLongInt &b) const { return operator|(b.GetValue()); }

    template <typename T>
    LongLongInt operator^(const T &b) const { return LongLongInt(value ^ b); }
    LongLongInt operator^(const LongLongInt &b) const { return operator^(b.GetValue()); }

    template <typename T>
    LongLongInt operator<<(const T &b) const { return LongLongInt(value << b); }
    LongLongInt operator<<(const LongLongInt &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    LongLongInt operator>>(const T &b) const { return LongLongInt(value >> b); }
    LongLongInt operator>>(const LongLongInt &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const LongLongInt &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const LongLongInt &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const LongLongInt &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const LongLongInt &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const LongLongInt &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const LongLongInt &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator long long int() override { return value; }

    inline long long int GetValue() const { return value; }
  private:
    long long int value;
};

#endif
