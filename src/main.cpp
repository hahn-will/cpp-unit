#include <iostream>
#include <utility>
#include <functional>
#include <primitive_type_all.hpp>

using namespace std;

template<std::size_t... I>
void unpack(std::function<bool()> func, Object **arr, index_sequence<I...>) {
  func(*arr[I]...);
}
static constexpr size_t make_constexpr(const size_t n) {
  return n;
}

template<typename ...args>
void unp(args... arg, std::function<bool()>) {

}

int main() {
  Object *arr[] = { new Integer(1), new Double(2.3), new SignedChar('c') };


  
  std::function<bool(int a, double b, signed char c)> func = [](int a, double b, signed char c) -> bool {
    cout << a << b << c << endl;
    return true;
  };
  std::function<bool(Object **arr, function<bool(int a, double b, signed char c)>)> f1 = [](Object **arr, function<bool(int a, double b, signed char c)>) -> bool {

    return true;
  };
  unpack(func, arr, make_index_sequence<3>{});
}
