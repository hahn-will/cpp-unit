#ifndef LONGDOUBLE_HPP__
#define LONGDOUBLE_HPP__

#include <ostream>

#include "Object.hpp"

class LongDouble : public Object {
  public:
    LongDouble(long double value) : Object(), value(value) {}
    ~LongDouble() {}

    // Assignment Operators
    template <typename T>
    LongDouble& operator=(const T a) { value = a; return *this; }
    LongDouble& operator=(const LongDouble &b) { return operator=(b.GetValue()); }

    template <typename T>
    LongDouble& operator+=(const T a) { value += a; return *this; }
    LongDouble& operator+=(const LongDouble &b) { return operator+=(b.GetValue()); }

    template <typename T>
    LongDouble& operator-=(const T a) { value -= a; return *this; }
    LongDouble& operator-=(const LongDouble &b) { return operator-=(b.GetValue()); }

    template <typename T>
    LongDouble& operator*=(const T a) { value *= a; return *this; }
    LongDouble& operator*=(const LongDouble &b) { return operator*=(b.GetValue()); }

    template <typename T>
    LongDouble& operator/=(const T a) { value /= a; return *this; }
    LongDouble& operator/=(const LongDouble &b) { return operator/=(b.GetValue()); }

    // Increment Decrement operators
    LongDouble& operator++() { ++value; return *this; }
    LongDouble operator++(int) { long double temp = value; value++; return LongDouble(temp); }
    LongDouble& operator--() { --value; return *this; }
    LongDouble operator--(int) { long double temp = value; value--; return LongDouble(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const LongDouble &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const LongDouble &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    LongDouble operator+() const { return LongDouble(+value); }
    LongDouble operator-() const { return LongDouble(-value); }

    // Binary operators
    template <typename T>
    LongDouble operator+(const T &b) const { return LongDouble(value + b); }
    LongDouble operator+(const LongDouble &b) const { return operator+(b.GetValue()); }

    template <typename T>
    LongDouble operator-(const T &b) const { return LongDouble(value - b); }
    LongDouble operator-(const LongDouble &b) const { return operator-(b.GetValue()); }

    template <typename T>
    LongDouble operator*(const T &b) const { return LongDouble(value * b); }
    LongDouble operator*(const LongDouble &b) const { return operator*(b.GetValue()); }

    template <typename T>
    LongDouble operator/(const T &b) const { return LongDouble(value / b); }
    LongDouble operator/(const LongDouble &b) const { return operator/(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const LongDouble &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const LongDouble &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const LongDouble &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const LongDouble &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const LongDouble &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const LongDouble &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator long double() override { return value; }

    inline long double GetValue() const { return value; }
  private:
    long double value;
};

#endif
