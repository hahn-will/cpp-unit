#ifndef WCHAR_HPP__
#define WCHAR_HPP__

#include <ostream>

#include "Object.hpp"

class WChar : public Object {
  public:
    WChar(wchar_t value) : Object(), value(value) {}
    ~WChar() {}

    // Assignment Operators
    template <typename T>
    WChar& operator=(const T a) { value = a; return *this; }
    WChar& operator=(const WChar &b) { return operator=(b.GetValue()); }

    template <typename T>
    WChar& operator+=(const T a) { value += a; return *this; }
    WChar& operator+=(const WChar &b) { return operator+=(b.GetValue()); }

    template <typename T>
    WChar& operator-=(const T a) { value -= a; return *this; }
    WChar& operator-=(const WChar &b) { return operator-=(b.GetValue()); }

    template <typename T>
    WChar& operator*=(const T a) { value *= a; return *this; }
    WChar& operator*=(const WChar &b) { return operator*=(b.GetValue()); }

    template <typename T>
    WChar& operator/=(const T a) { value /= a; return *this; }
    WChar& operator/=(const WChar &b) { return operator/=(b.GetValue()); }

    template <typename T>
    WChar& operator%=(const T a) { value %= a; return *this; }
    WChar& operator%=(const WChar &b) { return operator%=(b.GetValue()); }

    template <typename T>
    WChar& operator&=(const T a) { value &= a; return *this; }
    WChar& operator&=(const WChar &b) { return operator&=(b.GetValue()); }

    template <typename T>
    WChar& operator|=(const T a) { value |= a; return *this; }
    WChar& operator|=(const WChar &b) { return operator|=(b.GetValue()); }

    template <typename T>
    WChar& operator^=(const T a) { value ^= a; return *this; }
    WChar& operator^=(const WChar &b) { return operator^=(b.GetValue()); }

    template <typename T>
    WChar& operator<<=(const T a) { value <<= a; return *this; }
    WChar& operator<<=(const WChar &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    WChar& operator>>=(const T a) { value >>= a; return *this; }
    WChar& operator>>=(const WChar &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    WChar& operator++() { ++value; return *this; }
    WChar operator++(int) { wchar_t temp = value; value++; return WChar(temp); }
    WChar& operator--() { --value; return *this; }
    WChar operator--(int) { wchar_t temp = value; value--; return WChar(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const WChar &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const WChar &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    WChar operator+() const { return WChar(+value); }
    WChar operator-() const { return WChar(-value); }
    WChar operator~() const { return WChar(~value); }

    // Binary operators
    template <typename T>
    WChar operator+(const T &b) const { return WChar(value + b); }
    WChar operator+(const WChar &b) const { return operator+(b.GetValue()); }

    template <typename T>
    WChar operator-(const T &b) const { return WChar(value - b); }
    WChar operator-(const WChar &b) const { return operator-(b.GetValue()); }

    template <typename T>
    WChar operator*(const T &b) const { return WChar(value * b); }
    WChar operator*(const WChar &b) const { return operator*(b.GetValue()); }

    template <typename T>
    WChar operator/(const T &b) const { return WChar(value / b); }
    WChar operator/(const WChar &b) const { return operator/(b.GetValue()); }

    template <typename T>
    WChar operator%(const T &b) const { return WChar(value % b); }
    WChar operator%(const WChar &b) const { return operator%(b.GetValue()); }

    template <typename T>
    WChar operator&(const T &b) const { return WChar(value & b); }
    WChar operator&(const WChar &b) const { return operator&(b.GetValue()); }

    template <typename T>
    WChar operator|(const T &b) const { return WChar(value | b); }
    WChar operator|(const WChar &b) const { return operator|(b.GetValue()); }

    template <typename T>
    WChar operator^(const T &b) const { return WChar(value ^ b); }
    WChar operator^(const WChar &b) const { return operator^(b.GetValue()); }

    template <typename T>
    WChar operator<<(const T &b) const { return WChar(value << b); }
    WChar operator<<(const WChar &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    WChar operator>>(const T &b) const { return WChar(value >> b); }
    WChar operator>>(const WChar &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const WChar &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const WChar &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const WChar &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const WChar &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const WChar &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const WChar &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator wchar_t() override { return value; }

    inline wchar_t GetValue() const { return value; }
  private:
    wchar_t value;
};

#endif
