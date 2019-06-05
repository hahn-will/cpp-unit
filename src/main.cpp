#include <iostream>
#include <utility>
#include <functional>
#include <primitive_type_all.hpp>

using namespace std;

template<std::size_t... I, typename ... Args>
void unpack(std::function<bool(Args...)> func, Object **arr, index_sequence<I...>) {
  func(*arr[I]...);
}

template<typename ... Args>
void call_func(Args... args) {

}

static constexpr size_t make_constexpr(const size_t n) {
  return n;
}

int main() {
  auto t1 = [](int a, double b, signed char c) -> bool {
    return true;
  };



  auto unpack = [](std::function<bool(int a, double b, signed char c)> func, Object **arr, index_sequence<I...>) {
    
  }

  
  
  std::function<bool(int a, double b, signed char c)> func = [](int a, double b, signed char c) -> bool {
    cout << a << b << c << endl;
    return true;
  };
  std::function<bool(Object **arr, function<bool(int a, double b, signed char c)>)> f1 = [](Object **arr, function<bool(int a, double b, signed char c)>) -> bool {

    return true;
  };
  unpack(func, arr, make_index_sequence<3>{});
}
