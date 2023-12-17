#include <complex/complex.hpp>

bool testParse(const std::string& str) {
  using namespace std;
  stringstream istrm(str);
  Complex z{};
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str;
  }
  else {
    cout << "Read error : " << str;
  }
  return istrm.good();
}

int main() {
  Complex x{};
  Complex y{};
  double d;

  x = Complex{ 2, 3 };
  y = Complex{ 0.0, 0.0 };
  d = 0.0;
  try {
    std::cout << "1) " << x << "/" << d << "\nExpected: Divide by zero exception\n";
    x / d;
  }
  catch (std::overflow_error& e) {
    std::cout << e.what() << '\n';
  }
  try {
    std::cout << "2) " << x << "/" << y << "\nExpected: Divide by zero exception\n";
    x / y;
  }
  catch (std::overflow_error& e) {
    std::cout << e.what() << '\n';
  }

  x = Complex{ 1.5, 2.0 };
  y = Complex{ 2.5, 3.5 };
  std::cout << "3) " << x << " + " << y << " == " << x + y
    << "\nExpected: {4.0, 5.5}\n";

  x = Complex{ 3.0, 5.0 };
  y = Complex{ 1.5, 2.5 };
  std::cout << "4) " << x << " - " << y << " == " << x - y
    << "\nExpected: {1.5, 2.5}\n";

  x = Complex{ 1.5, 2.0 };
  y = Complex{ 2.0, 3.0 };
  std::cout << "5) " << x << " * " << y << " == " << x * y
    << "\nExpected: {-3,8.5}\n";

  x = Complex{ 3.0, 5.0 };
  y = Complex{ 1.5, 2.5 };
  std::cout << "6) " << x << " / " << y << " == " << x / y
    << "\nExpected: {2, 0}\n";

  d = 2.5;
  x = Complex{ 1.5, 1.0 };
  std::cout << "7) " << d << " + " << x << " == " << d + x
    << "\nExpected: {4.0, 1.0}\n";
  std::cout << "8) " << x << " + " << d << " == " << x + d
    << "\nExpected: {4.0, 1.0}\n";

  x = Complex{ 1, 3 };
  d = 3.5;
  std::cout << "9) " << x << " - " << d << " == " << x - d
    << "\nExpected: {-2.5, 3}\n";
  std::cout << "10) " << d << " - " << x << " == " << d - x
    << "\nExpected: {2.5, -3}\n";

  d = 2.0;
  x = Complex{ 1.5, -1.0 };
  std::cout << "11) " << d << " * " << x << " == " << d * x << "\nExpected: {3.0, -2.0}\n";
  std::cout << "12) " << x << " * " << d << " == " << x * d << "\nExpected: {3.0, -2.0}\n";

  x = Complex{ -7.5, 2.5 };
  d = 2.5;
  std::cout << "13) " << x << " / " << d << " == " << x / d << "\nExpected: {-3, 1}\n";
  std::cout << "14) " << d << " / " << x << " == " << d / x << "\nExpected: {-0.3, -0.1}\n";

  std::cout << "Assignment\n";
  d = 43.23;
  x = Complex{ 1, 1 };
  y = Complex{ 12, 33 };
  std::cout << "15) " << x << " = " << d << "| x = ";

  std::cout << "16) " << x << " = " << y << "| x = ";
  x = y;
  std::cout << x << "\nExpected: {12, 33}\n";

  x = Complex{ 11.1, 9.8 };
  y = Complex{ 7, -9 };
  d = 10.0;
  std::cout << "17) " << x << " /= " << y << "| x = ";
  x /= y;
  std::cout << x << "\nExpected: {-0.0807, 1.2961}\n";

  std::cout << "18) " << x << " /= " << d << "| x = ";
  x /= d;
  std::cout << x << "\nExpected: {-0.00807, 0.12961}\n";

  x = Complex{ 1.12, 2.49 };
  y = Complex{ 1.88, 2.51 };
  d = 1.0;
  std::cout << "19) " << x << " += " << y << "| x = ";
  x += y;
  std::cout << x << "\nExpected: {3, 5}\n";

  std::cout << "20) " << x << " += " << d << "| x = ";
  x += d;
  std::cout << x << "\nExpected: {4, 5}\n";

  std::cout << "21) " << x << " -= " << y << "| x = ";
  x -= y;
  std::cout << x << "\nExpected: {2.12, 2.49}\n";

  std::cout << "21) " << x << " -= " << d << "| x = ";
  x -= d;
  std::cout << x << "\nExpected: {1.12, 2.49}\n";

  x = Complex{ 1.0, 1.0 };
  y = Complex{ 5, 0 };
  std::cout << "22) " << x << " *= " << y << "| x = ";
  x *= y;
  std::cout << x << "\nExpected: {5, 5}\n";

  d = -1.0;
  std::cout << "23) " << x << " *= " << d << "| x = ";
  x *= d;
  std::cout << x << "\nExpected: {-5, -5}\n";

  y = Complex{ 12.5, 133123 };
  std::cout << "28) " << y << " == " << x << ": " << (y == x) << "\nExpected: 0\n";
  std::cout << "29) " << y << " != " << x << ": " << (y != x) << "\nExpected: 1\n";


  x = Complex{ 12, 0.1 + 0.2 };
  y = Complex{ 12, 0.3 };
  std::cout << "31) Testing comparison of floating point numbers \
{12, 0.1 + 0.2} == {12, 0.3}\n";
  std::cout << "Result -> " << (x.re == y.re && x.im == y.im)
    << ":Comparing floating point numbers using \"==\"" << '\n';
  std::cout << "Result -> " << (x == y)
    << ":Comparing floating point numbers using \"epsilon\"\n\n";

  testParse("{1.9,0.1}");
  testParse("{    1.9,    0.1}");
  testParse("(1.9,,0.1)");
  testParse("123///12312");
}
