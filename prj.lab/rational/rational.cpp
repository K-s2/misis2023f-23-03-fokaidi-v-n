#include <rational/rational.hpp>
#include <stdexcept>
#include <iostream>


std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
  ostrm << num_ << separator_slash << den_;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
  char slash(0);
  istrm >> num_ >> slash >> den_;
  if (istrm && (separator_slash == slash)) {
    gcd();
  }
  return istrm;
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  Rational ans = lhs;
  ans += rhs;
  return ans;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept  {
  num_ = num_ + den_ * rhs;
  gcd();
  return *this;
}

Rational operator+(const Rational& rhs, const int64_t lhs) noexcept {
  Rational ans = rhs;
  ans += lhs;
  return ans;
}

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }

Rational& Rational::operator-=(const Rational& rhs) noexcept  {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept  {
  Rational ans = lhs;
  ans -= rhs;
  return ans;
}

Rational& Rational::operator-=(const int64_t rhs) noexcept  {
  num_ = num_ - rhs * den_;
  gcd();
  return *this;
}

Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
  Rational ans = lhs;
  ans -= rhs;
  return ans;
}


Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept  {
  Rational ans = lhs;
  ans *= rhs;
  return ans;
}

Rational Rational::operator*=(const int64_t rhs) noexcept {
  num_ = num_ * rhs;
  gcd();
  return *this;
}

Rational operator*(const Rational& lhs, const int64_t rhs) noexcept {
  Rational ans = lhs;
  ans *= rhs;
  return ans;
}


Rational& Rational::operator/=(const Rational& rhs) {
  num_ = num_ * rhs.den_;
  den_ = den_ * rhs.num_;
  gcd();
  return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational ans = lhs;
  ans /= rhs;
  return ans;
}

Rational& Rational::operator/=(const int64_t rhs) {
  den_ = den_ * rhs;
  gcd();
  return *this;
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  Rational ans = lhs;
  ans /= rhs;
  return ans;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
  return ((num_ == rhs.num()) && (den_ == rhs.den()));
}

bool Rational::operator>=(const Rational & rhs) const noexcept {
  return((num_ * rhs.den()) >= rhs.num() * den_);
}

bool Rational::operator>(const Rational& rhs) const noexcept {
  return((num_ * rhs.den()) > rhs.num() * den_);
}

bool Rational:: operator<(const Rational& rhs) const noexcept {
  return((num_ * rhs.den()) < rhs.num() * den_);
}

bool Rational::operator<=(const Rational& rhs) const noexcept {
  return ((num_ * rhs.den()) <= rhs.num() * den_);
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
  return !((num_ == rhs.num()) && (den_ == rhs.den()));
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept{
  return rhs.ReadFrom(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

int64_t Rational::num() const noexcept {
  return num_;
}

int64_t Rational::den() const noexcept {
  return den_;
}

int Rational::num_gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return num_gcd(b, a % b);
}

void Rational::gcd() {
  int64_t gcd_ = num_gcd(num_, den_);
  num_ = num_ / gcd_;
  den_ = den_ / gcd_;
  if ((den_ < 0) || ((den_ < 0)&&(num_ <0))) {
    num_ = num_ * (-1);
    den_ = den_ * (-1);
  }
  if (den_ == 0) {
    throw std::runtime_error("Division by zero");
  }
}
