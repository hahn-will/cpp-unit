#include "Integer.hpp"

Integer operator+(Integer a, const Integer &b) {
  return a.GetValue() + b.GetValue();
}

Integer operator+(Integer a, const int b) {
  return a.GetValue() + b;
}

Integer operator+(int a, const Integer &b) {
  return a + b.GetValue();
}

Integer& Integer::operator+=(Integer a) {
  value += a.GetValue();
  return *this;
}

Integer::Integer(int value) : Object(), value(value) {
}

Integer::~Integer() {}

Integer& Integer::operator=(const int new_value) {
  value = new_value;
  return *this;
}
Integer& Integer::operator=(const Integer &new_value) {
  value = new_value.GetValue();
  return *this;
}

Integer::operator int() {
  return value;
}
