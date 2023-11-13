#include "complex.hpp"
#indef COMPLEX_HPP
#define COMPLEX_HPP


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
int main()
{
  operator_test_1();
  return 0;
}

#endif
