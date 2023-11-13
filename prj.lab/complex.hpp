#include <iostream>
#include <sstream>
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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

#endif

