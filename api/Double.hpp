#ifndef DOUBLE_HPP__
#define DOUBLE_HPP__

#include <ostream>

#include "Object.hpp"

class Double : public Object {
  public:
    Double(double value) : Object(), value(value) {}
    ~Double() {}

    // Assignment Operators
    template <typename T>
    Double& operator=(const T a) { value = a; return *this; }
    Double& operator=(const Double &b) { return operator=(b.GetValue()); }

    template <typename T>
    Double& operator+=(const T a) { value += a; return *this; }
    Double& operator+=(const Double &b) { return operator+=(b.GetValue()); }

    template <typename T>
    Double& operator-=(const T a) { value -= a; return *this; }
    Double& operator-=(const Double &b) { return operator-=(b.GetValue()); }

    template <typename T>
    Double& operator*=(const T a) { value *= a; return *this; }
    Double& operator*=(const Double &b) { return operator*=(b.GetValue()); }

    template <typename T>
    Double& operator/=(const T a) { value /= a; return *this; }
    Double& operator/=(const Double &b) { return operator/=(b.GetValue()); }

    // Increment Decrement operators
    Double& operator++() { ++value; return *this; }
    Double operator++(int) { double temp = value; value++; return Double(temp); }
    Double& operator--() { --value; return *this; }
    Double operator--(int) { double temp = value; value--; return Double(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const Double &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const Double &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    Double operator+() const { return Double(+value); }
    Double operator-() const { return Double(-value); }

    // Binary operators
    template <typename T>
    Double operator+(const T &b) const { return Double(value + b); }
    Double operator+(const Double &b) const { return operator+(b.GetValue()); }

    template <typename T>
    Double operator-(const T &b) const { return Double(value - b); }
    Double operator-(const Double &b) const { return operator-(b.GetValue()); }

    template <typename T>
    Double operator*(const T &b) const { return Double(value * b); }
    Double operator*(const Double &b) const { return operator*(b.GetValue()); }

    template <typename T>
    Double operator/(const T &b) const { return Double(value / b); }
    Double operator/(const Double &b) const { return operator/(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const Double &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const Double &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const Double &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const Double &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const Double &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const Double &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator double() override { return value; }

    inline double GetValue() const { return value; }
  private:
    double value;
};

#endif
