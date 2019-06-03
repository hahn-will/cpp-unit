#include <iostream>
#include <string>
#include <locale>

using namespace std;

string ToUpper(string str) {
  string o = "";
  locale loc;
  for (unsigned i = 0; i < str.size(); i++ ) {
    o += toupper(str[i], loc);
  }
  return o;
}

int main(int argc, char *argv[]) {
  if (argc < 3) 
    return -1;

  const string assignment_arr[] = { "=", "+=", "-=", "*=", "/=", "%=", "&=",
                                    "|=", "^=", "<<=", ">>=" };

  const string bin_arith_arr[] = { "+", "-", "*", "/", "%", "&", "|", "^", "<<", ">>" };
  const string comp_arr[] = { "==", "!=", "<", ">", "<=", ">=" };

  string name = argv[1];
  string type = argv[2];
  cout << "#ifndef " << ToUpper(name) << "_HPP__" << endl;
  cout << "#define " << ToUpper(name) << "_HPP__" << endl << endl;
  cout << "#include <ostream>" << endl << endl;
  cout << "#include \"Object.hpp\"" << endl << endl;
  cout << "class " << name << " : public Object {" << endl;
  cout << "  public:" << endl;
  cout << "    " << name << "(" << type << " value) : Object(), value(value) {}" << endl;
  cout << "    ~" << name << "() {}" << endl << endl;

  cout << "    // Assignment Operators\n";

  for (int i = 0; i < 11; i++) {
    cout << "    template <typename T>\n    ";
    cout << argv[1] << "& operator" << assignment_arr[i] << "(const T a) { value ";
    cout << assignment_arr[i] << " a; return *this; }" << endl << "    ";
    cout << argv[1] << "& operator" << assignment_arr[i] << "(const " << argv[1];
    cout << " &b) { return operator" << assignment_arr[i] << "(b.GetValue()); }" << endl;
    cout << endl;
  }
  cout << "    // Increment Decrement operators\n    " << name;
  cout << "& operator++() { ++value; return *this; }\n    ";
  cout << name << " operator++(int) { " << type << " temp = value; value++; return ";
  cout << name << "(temp); }\n    " << name;
  cout << "& operator--() { --value; return *this; }\n    ";
  cout << name << " operator--(int) { " << type << " temp = value; value--; return ";
  cout << name << "(temp); }\n" << endl;
  cout << "    // Logical operators" << endl << "    ";
  cout << "bool operator!() const { return !value; }\n\n    template <typename T>\n    ";
  cout << "bool operator&&(const T &b) const { return value && b; }\n    ";
  cout << "bool operator&&(const " << name << " &b) const { return operator&&(b.GetValue()); }\n\n";
  cout << "    template <typename T>\n    ";
  cout << "bool operator||(const T &b) const { return value || b; }\n    ";
  cout << "bool operator||(const " << name << " &b) const { return operator||(b.GetValue()); }\n\n";
  cout << "    // Arithmetic Operators\n    // Unary Operators\n    ";
  cout << name << " operator+() const { return " << name << "(+value); }\n    ";
  cout << name << " operator-() const { return " << name << "(-value); }\n    ";
  cout << name << " operator~() const { return " << name << "(~value); }\n\n    ";
  cout << "// Binary operators\n";
  for (int i = 0; i < 10; i++) {
    cout << "    template <typename T>\n    ";
    cout << name << " operator" << bin_arith_arr[i] << "(const T &b) const ";
    cout << "{ return " << name << "(value " << bin_arith_arr[i] << " b); }\n    ";
    cout << name << " operator" << bin_arith_arr[i] << "(const " << name << " &b) const ";
    cout << "{ return operator" << bin_arith_arr[i] << "(b.GetValue()); }" << endl << endl;
  }
  cout << "    // Comparison Operators\n";
  for (int i = 0; i < 6; i++) {
    cout << "    template <typename T>\n    ";
    cout << "bool operator" << comp_arr[i] << "(const T &b) const { return value ";
    cout << comp_arr[i] << " b; }\n    ";
    cout << "bool operator" << comp_arr[i] << "(const " << name << " &b) const {";
    cout << " return operator" << comp_arr[i] << "(b.GetValue()); }" << endl << endl;
  }
  cout << "    ";
  cout << "std::ostream& operator<<(std::ostream &os) { os << value; return os; }" << endl << endl;
  cout << "    operator " << type << "() override { return value; }" << endl << endl;
  cout << "    inline " << type << " GetValue() const { return value; }" << endl;
  cout << "  private:\n    " << type << " value;\n";
  cout << "};" << endl << endl;

  cout << "#endif" << endl;
}
