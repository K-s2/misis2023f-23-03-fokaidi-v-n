#pragma once
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <cstdint>
#include <iosfwd>

class Rational {

public:
  Rational() : num_(0), den_(1) {}
  //конструктор по умолчанию с одним аргументом
  Rational(const int64_t numerator) : num_(numerator), den_(1) {}
  //конструктор с двумя аргументами
  Rational(const int64_t numerator, const int64_t denumerator) {
    num_ = numerator;
    den_ = denumerator;
    gcd();
  }
  ~Rational() = default;
  [[nodiscard]] Rational operator-() const noexcept { return { -num_, den_ }; }
  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
  std::istream& ReadFrom(std::istream& istrm) noexcept;

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator+=(const int64_t rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator-=(const int64_t rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational operator*=(const int64_t rhs) noexcept;
  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int64_t rhs) ;

  bool operator==(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
  bool operator>=(const Rational& rhs) const noexcept;
  bool operator>(const Rational& rhs) const noexcept;
  bool operator<(const Rational& rhs) const noexcept;
  bool operator<=(const Rational& rhs) const noexcept;

  int64_t num() const noexcept;
  int64_t den() const noexcept;

private:
  int64_t num_ = 0;
  int64_t den_ = 1;

  int num_gcd(int64_t a, int64_t b);
  void gcd();

  static const char separator_slash{ '/' };
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const int64_t rhs);

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
Rational operator/(const int64_t lhs, const Rational& rhs) ;


#endif
