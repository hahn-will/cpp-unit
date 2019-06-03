#ifndef FLOAT_HPP__
#define FLOAT_HPP__

#include <ostream>

#include "Object.hpp"

class Float : public Object {
  public:
    Float(float value) : Object(), value(value) {}
    ~Float() {}

    // Assignment Operators
    template <typename T>
    Float& operator=(const T a) { value = a; return *this; }
    Float& operator=(const Float &b) { return operator=(b.GetValue()); }

    template <typename T>
    Float& operator+=(const T a) { value += a; return *this; }
    Float& operator+=(const Float &b) { return operator+=(b.GetValue()); }

    template <typename T>
    Float& operator-=(const T a) { value -= a; return *this; }
    Float& operator-=(const Float &b) { return operator-=(b.GetValue()); }

    template <typename T>
    Float& operator*=(const T a) { value *= a; return *this; }
    Float& operator*=(const Float &b) { return operator*=(b.GetValue()); }

    template <typename T>
    Float& operator/=(const T a) { value /= a; return *this; }
    Float& operator/=(const Float &b) { return operator/=(b.GetValue()); }

    template <typename T>
    Float& operator%=(const T a) { value %= a; return *this; }
    Float& operator%=(const Float &b) { return operator%=(b.GetValue()); }

    template <typename T>
    Float& operator&=(const T a) { value &= a; return *this; }
    Float& operator&=(const Float &b) { return operator&=(b.GetValue()); }

    template <typename T>
    Float& operator|=(const T a) { value |= a; return *this; }
    Float& operator|=(const Float &b) { return operator|=(b.GetValue()); }

    template <typename T>
    Float& operator^=(const T a) { value ^= a; return *this; }
    Float& operator^=(const Float &b) { return operator^=(b.GetValue()); }

    template <typename T>
    Float& operator<<=(const T a) { value <<= a; return *this; }
    Float& operator<<=(const Float &b) { return operator<<=(b.GetValue()); }

    template <typename T>
    Float& operator>>=(const T a) { value >>= a; return *this; }
    Float& operator>>=(const Float &b) { return operator>>=(b.GetValue()); }

    // Increment Decrement operators
    Float& operator++() { ++value; return *this; }
    Float operator++(int) { float temp = value; value++; return Float(temp); }
    Float& operator--() { --value; return *this; }
    Float operator--(int) { float temp = value; value--; return Float(temp); }

    // Logical operators
    bool operator!() const { return !value; }

    template <typename T>
    bool operator&&(const T &b) const { return value && b; }
    bool operator&&(const Float &b) const { return operator&&(b.GetValue()); }

    template <typename T>
    bool operator||(const T &b) const { return value || b; }
    bool operator||(const Float &b) const { return operator||(b.GetValue()); }

    // Arithmetic Operators
    // Unary Operators
    Float operator+() const { return Float(+value); }
    Float operator-() const { return Float(-value); }

    // Binary operators
    template <typename T>
    Float operator+(const T &b) const { return Float(value + b); }
    Float operator+(const Float &b) const { return operator+(b.GetValue()); }

    template <typename T>
    Float operator-(const T &b) const { return Float(value - b); }
    Float operator-(const Float &b) const { return operator-(b.GetValue()); }

    template <typename T>
    Float operator*(const T &b) const { return Float(value * b); }
    Float operator*(const Float &b) const { return operator*(b.GetValue()); }

    template <typename T>
    Float operator/(const T &b) const { return Float(value / b); }
    Float operator/(const Float &b) const { return operator/(b.GetValue()); }

    template <typename T>
    Float operator%(const T &b) const { return Float(value % b); }
    Float operator%(const Float &b) const { return operator%(b.GetValue()); }

    template <typename T>
    Float operator&(const T &b) const { return Float(value & b); }
    Float operator&(const Float &b) const { return operator&(b.GetValue()); }

    template <typename T>
    Float operator|(const T &b) const { return Float(value | b); }
    Float operator|(const Float &b) const { return operator|(b.GetValue()); }

    template <typename T>
    Float operator^(const T &b) const { return Float(value ^ b); }
    Float operator^(const Float &b) const { return operator^(b.GetValue()); }

    template <typename T>
    Float operator<<(const T &b) const { return Float(value << b); }
    Float operator<<(const Float &b) const { return operator<<(b.GetValue()); }

    template <typename T>
    Float operator>>(const T &b) const { return Float(value >> b); }
    Float operator>>(const Float &b) const { return operator>>(b.GetValue()); }

    // Comparison Operators
    template <typename T>
    bool operator==(const T &b) const { return value == b; }
    bool operator==(const Float &b) const { return operator==(b.GetValue()); }

    template <typename T>
    bool operator!=(const T &b) const { return value != b; }
    bool operator!=(const Float &b) const { return operator!=(b.GetValue()); }

    template <typename T>
    bool operator<(const T &b) const { return value < b; }
    bool operator<(const Float &b) const { return operator<(b.GetValue()); }

    template <typename T>
    bool operator>(const T &b) const { return value > b; }
    bool operator>(const Float &b) const { return operator>(b.GetValue()); }

    template <typename T>
    bool operator<=(const T &b) const { return value <= b; }
    bool operator<=(const Float &b) const { return operator<=(b.GetValue()); }

    template <typename T>
    bool operator>=(const T &b) const { return value >= b; }
    bool operator>=(const Float &b) const { return operator>=(b.GetValue()); }

    std::ostream& operator<<(std::ostream &os) { os << value; return os; }

    operator float() override { return value; }

    inline float GetValue() const { return value; }
  private:
    float value;
};

#endif
