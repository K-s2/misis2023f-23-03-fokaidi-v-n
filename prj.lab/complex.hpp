#ifndef COMPLEX_H
#define COMPLEX_H

#include <sstream>

struct Complex {
  // конструктор по умолчанию
  Complex() : re(0.0), im(0.0) {}

  // конструктор с одним аргументом
  Complex(const double real) : re(real), im(0.0) {}

  // конструктор с двумя аргументами
  Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

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

  std::ostream& writeTo(std::ostream& ostrm) const;

  std::istream& readFrom(std::istream& istrm);

  double re{ 0.0 };
  double im{ 0.0 };

  static const char leftBrace{ '{' };
  static const char separator_comma{ ',' };
  static const char separator_space{ ' ' };
  static const char rightBrace{ '}' };
};

bool operator==(const Complex& lhs, const Complex& rhs);

bool operator==(const double lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const double rhs);

bool operator!=(const Complex& lhs, const Complex& rhs);

bool operator!=(const Complex& lhs, const double rhs);

bool operator!=(const double lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);

Complex& operator*=(Complex& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const double rhs);

Complex operator*(const double lhs, const Complex& rhs);

Complex& operator/=(Complex& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const double rhs);

Complex pow(const Complex& lhs, const int rhs);

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs);

std::istream& operator>>(std::istream& istrm, Complex& rhs);

#endif
