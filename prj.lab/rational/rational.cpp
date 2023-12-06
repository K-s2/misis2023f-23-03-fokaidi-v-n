#include "rational.hpp"


std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << num_ << separator_slash << den_;
  return ostrm;
}

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.WriteTo(ostrm);
}

void test1() {
  Rational r1;
  r1 = Rational{ 5 , 2 };
  std::cout << r1 << " ";
  Rational r2;
  r2 = Rational{ 1 , 2 };
  r1 += r2;
  std::cout << r1 << " ";
  Rational r3{ 5, 2 };
  r3 -= r2;
  std::cout << r3;
  Rational r4;
  r4 = { 5, 2 };
  r4 *= r2;
  std::cout << " " << r4;
  Rational r5;
  r5 = { 5, 2 };
  r5 /= r2;
  std::cout << " " << r5;
}

int main() {
  test1();
}
