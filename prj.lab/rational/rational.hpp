#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <sstream>

class Rational {

public:
  Rational() : num_(0), den_(1) {}
  //конструктор по умолчанию с одним аргументом
  Rational(const int64_t numerator) : num_(numerator), den_(1) {}
  //конструктор с двумя аргументами
  Rational(const int64_t numerator, const int64_t denumerator) : num_(numerator), den_(denumerator) {}

  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);

  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int64_t rhs);
  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int64_t rhs);
  Rational& operator*=(const Rational& rhs);
  Rational operator*=(const int64_t rhs);
  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int64_t rhs);

  int64_t num() const;
  int64_t den() const;

private:
  int64_t num_ = 1;
  int64_t den_ = 0;

  int num_gcd(int64_t a, int64_t b);
  void gcd();

  static const char separator_slash;
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rhs);
Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const int64_t rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const int64_t rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const int64_t rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int64_t rhs);

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator==(const Rational& lhs, const int64_t rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const int64_t rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const int64_t rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const int64_t rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const int64_t rhs);
