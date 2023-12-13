#include <complex/complex.hpp>
#include <iostream>

void operator_test_1() {
  Complex x, y;
  double d;
  int e;
  std::cout << "----------------------------" << std::endl;

  std::cout << "\n \t operator + test \n" << std::endl;

  x = Complex{ 2.5, 2.1 };
  y = Complex{ 2.5, 3.5 };
  std::cout << x << " + " << y << " = " << x + y << " Expected: {5, 5.6}\n";

  x = Complex{ -2.5, 2.1 };
  y = Complex{ 2.5, -3.5 };
  std::cout << x << " x " << y << " = " << x + y << " Expected: {0, -1.4}\n";

  d = 1.0;
  x = Complex{ 2.0, -1.0 };
  std::cout << x << " + " << d << " = " << x + d << " Expected: {3, -1}\n";

  d = 1.6;
  x = Complex{ 2.5, 1.6 };
  std::cout << d << " + " << x << " = " << d + x << " Expected: {4.1, 1.6}\n";
}

void operator_test_2() {
  Complex x(0), y(0);
  double d = 0;
  int e = 0;

  std::cout << "\n \t = test \n" << std::endl;

  d = 4.3;
  x = Complex{ 1, 1 };
  y = Complex{ 1, 3 };
  std::cout << "x is " << x << " d is " << d << " x = d is ";
  x = d;
  std::cout << x << " Expected: {4.3, 0}\n";

  std::cout << "x is " << x << " y is " << y << " x = y ";
  x = y;
  std::cout << x << " Expected: {1, 3}\n";

  x = Complex{ 1, 1 };
  d = 2.8;
  std::cout << "x is " << x << " d is " << d << " x = d is ";
  x = d;
  std::cout << x << " Expected: {2.8, 0}\n";

  x = Complex{ 12,13 };
  y = Complex{ 13,1 };
  std::cout << "x is " << x << " y is " << y << " x = y is ";
  x = y;
  std::cout << x << " Expected: {13,1}\n";

  std::cout << "----------------------------" << std::endl;
}

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    std::cout << "Read success: " << str << " -> " << z << std::endl;
  }
  else {
    std::cout << "Read error : " << str << " -> " << z << std::endl;
  }
  return istrm.good();
}

int main()
{
  testParse("{3.6,4}");
  testParse("{1.9, 4}");
  testParse("{3.9,4");
  operator_test_1();
  operator_test_2();
  return 0;
}
