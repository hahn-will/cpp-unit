#ifndef BOOL_HPP__
#define BOOL_HPP__

#include <ostream>

#include "Object.hpp"

class Bool : public Object {
  public:
    Bool(bool value) : Object(), value(value) {}
    ~Bool() {}

    // Assignment Operators
    template <typename T>
    Bool& operator=(const T a) { value = a; return *this; }
    Bool& operator=(const Bool &b) { return operator=(b.GetValue()); }

    template <typename T>
    Bool& operator+=(const T a) { value += a; return *this; }
    Bool& operator+=(const Bool &b) { return operator+=(b.GetValue()); }

    template <typename T>
    Bool& operator-=(const T a) { value -= a; return *this; }
    Bool& operator-=(const Bool &b) { return operator-=(b.GetValue()); }

    template <typename T>
    Bool& operator*=(const T a) { value *= a; return *this; }
    Bool& operator*=(const Bool &b) { return operator*=(b.GetValue()); }

    template <typename T>
    Bool& operator/=(const T a) { value /= a; return *this; }
    Bool& operator/=(const Bool &b) { return operator/=(b.GetValue()); }

    template <typename T>
    Bool& operator%=(const T a) { value %= a; return *this; }
    Bool& operator%=(const Bool &b) { return operator%=(b.GetValue()); }

    template <typename T>
    Bool& operator&=(const T a) { value &= a; return *this; }
    Bool& operator&=(const Bool &b) { return operator&=(b.GetValue()); }

    template <typename T>
    Bool& operator|=(const T a) { value |= a; return *this; }
    Bool& operator|=(const Bool &b) { return operator|=(b.GetValue()); }

    template <typename T>
    Bool& operator^=(const T a) { value ^= a; return *this; }
    Bool& operator^=(const Bool &b) { return operator^=(b.GetValue()); }

    template <typename T>
    Bool& operator<<=(const T a) { value <<= a; return *this; }
    Bool& operator<<=(const Bool &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    Bool& operator>>=(const T a) { value >>= a; return *this; }
    Bool& operator>>=(const Bool &b) { return operator>>=(b.GetValue()); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const Bool &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const Bool &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    Bool operator+() const { return Bool(+value); }
    Bool operator-() const { return Bool(-value); }
    Bool operator~() const { return Bool(~value); }

    // Binary operators
    template <typename T>
    Bool operator+(const T &b) const { return Bool(value + b); }
    Bool operator+(const Bool &b) const { return operator+(b.GetValue()); }

    template <typename T>
    Bool operator-(const T &b) const { return Bool(value - b); }
    Bool operator-(const Bool &b) const { return operator-(b.GetValue()); }

    template <typename T>
    Bool operator*(const T &b) const { return Bool(value * b); }
    Bool operator*(const Bool &b) const { return operator*(b.GetValue()); }

    template <typename T>
    Bool operator/(const T &b) const { return Bool(value / b); }
    Bool operator/(const Bool &b) const { return operator/(b.GetValue()); }

    template <typename T>
    Bool operator%(const T &b) const { return Bool(value % b); }
    Bool operator%(const Bool &b) const { return operator%(b.GetValue()); }

    template <typename T>
    Bool operator&(const T &b) const { return Bool(value & b); }
    Bool operator&(const Bool &b) const { return operator&(b.GetValue()); }

    template <typename T>
    Bool operator|(const T &b) const { return Bool(value | b); }
    Bool operator|(const Bool &b) const { return operator|(b.GetValue()); }

    template <typename T>
    Bool operator^(const T &b) const { return Bool(value ^ b); }
    Bool operator^(const Bool &b) const { return operator^(b.GetValue()); }

    template <typename T>
    Bool operator<<(const T &b) const { return Bool(value << b); }
    Bool operator<<(const Bool &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    Bool operator>>(const T &b) const { return Bool(value >> b); }
    Bool operator>>(const Bool &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const Bool &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const Bool &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const Bool &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const Bool &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const Bool &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const Bool &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator bool() override { return value; }

    inline bool GetValue() const { return value; }
  private:
    bool value;
};

#endif
