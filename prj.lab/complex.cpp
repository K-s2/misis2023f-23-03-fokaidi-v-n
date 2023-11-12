#include <iostream>
#include <sstream>

struct Complex
{
  Complex() : re(0.0), im(0.0) {}   // конструктор по умолчанию

  Complex(const double real) : re(real), im(0.0) {}   // конструктор с одним аргументом

  Complex(const double real, const double imaginary) : re(real), im(imaginary) {}   // конструктор с двумя аргументами

  Complex& operator+=(const Complex& rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
  }

  Complex& operator+=(const double rhs) {
    re += rhs;
    return *this;
  }

  Complex& operator-=(const Complex& rhs) {
    re -= rhs.re;
    im -= rhs.im;
    return *this;
  }

  Complex& operator-=(const double rhs) {
    re -= rhs;
    return *this;
  }

  Complex& operator*=(const double rhs) {
    re *= rhs;
    im *= rhs;
    return *this;
  }

  Complex& operator/=(const double rhs) {
    re /= rhs;
    im /= rhs;
    return *this;
  }

  std::ostream& writeTo(std::ostream& ostrm) const;   // объявляем функцию writeTo 

  std::istream& readFrom(std::istream& istrm);  // объявляем функцию readFrom 

  double re{ 0.0 };
  double im{ 0.0 };

  static const char leftBrace{ '{' };
  static const char separator_comma{ ',' };
  static const char separator_space{ ' ' };
  static const char rightBrace{ '}' };
};

//создаем блок перегруженных операторов 

bool operator==(const Complex& lhs, const Complex& rhs) {
  return (lhs.re == rhs.re) && (lhs.im == rhs.im);
}

bool operator==(const double lhs, const Complex& rhs) {
  return (lhs == rhs.re && rhs.im == 0);
}

bool operator==(const Complex& lhs, const double rhs) {
  return (lhs.re == rhs && lhs.im == 0);
}

bool operator!=(const Complex& lhs, const Complex& rhs) {
  return !(lhs == rhs);
}

bool operator!=(const Complex& lhs, const double rhs) {
  return !(lhs == Complex(rhs));
}

bool operator!=(const double lhs, const Complex& rhs) {
  return !(Complex(lhs) == rhs);
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex& operator*=(Complex& lhs, const Complex& rhs) {
  double newRe = lhs.re * rhs.re - lhs.im * rhs.im;
  double newIm = lhs.re * rhs.im + lhs.im * rhs.re;
  lhs.re = newRe;
  lhs.im = newIm;
  return lhs;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  double re = lhs.re * rhs.re - lhs.im * rhs.im;
  double im = lhs.re * rhs.im + lhs.im * rhs.re;
  return Complex(re, im);
}

Complex operator*(const Complex& lhs, const double rhs) {
  double re = lhs.re * rhs;
  double im = lhs.im * rhs;
  return Complex(re, im);
}

Complex operator*(const double lhs, const Complex& rhs) {
  double re = rhs.re * lhs;
  double im = rhs.im * lhs;
  return Complex(re, im);
}

Complex& operator/=(Complex& lhs, const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  double newRe = (lhs.re * rhs.re + lhs.im * rhs.im) / denominator;
  double newIm = (lhs.im * rhs.re - lhs.re * rhs.im) / denominator;
  lhs.re = newRe;
  lhs.im = newIm;
  return lhs;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  double re = (lhs.re * rhs.re + lhs.im * rhs.im) / denominator;
  double im = (lhs.im * rhs.re - lhs.re * rhs.im) / denominator;
  return Complex(re, im);
}

Complex operator/(const Complex& lhs, const double rhs) {
  double re = lhs.re / rhs;
  double im = lhs.im / rhs;
  return (Complex(re, im));
}

Complex pow(const Complex& lhs, const int rhs) {
  Complex result(1.0, 0.0);
  for (int i = 0; i < rhs; ++i) {
    result *= lhs;
  }
  return result;
}

// определение функции writeTo
std::ostream& Complex::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << re << separator_comma << separator_space << im << rightBrace;
  return ostrm;
}

// определение функции readFrom 
std::istream& Complex::readFrom(std::istream& istrm) {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char rightBrace(0);
  istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
  if (istrm.good())
  {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator_comma == comma) && (Complex::rightBrace == rightBrace))
    {
      re = real;
      im = imaginary;
    }
    else
    {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

// определяем поведение оператора << для Complex, мы вызываем функцию writeTo
inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.writeTo(ostrm);
}

// определяем поведение оператора >> для Complex, мы вызываем функцию readFrom
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.readFrom(istrm);
}

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
