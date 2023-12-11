#include <rational/rational.hpp>


std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << num_ << separator_slash << den_;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
  char slash(0);
  istrm >> num_ >> slash >> den_;
  if (istrm && (separator_slash == slash)) {
    gcd();
  }
  return istrm;
}

Rational& Rational::operator+=(const Rational& rhs) {
  num_ = num_ * rhs.den_ + den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}


Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational ans = lhs;
  ans += rhs;
  return ans;
}


Rational& Rational::operator+=(const int64_t rhs) {
  num_ = num_ + den_ * rhs;
  gcd();
  return *this;
}

Rational operator+(const Rational& lhs, const int64_t rhs) {
  Rational ans = lhs;
  ans += rhs;
  return ans;
}

Rational& Rational::operator-=(const Rational& rhs) {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational ans = lhs;
  ans -= rhs;
  return ans;
}

Rational& Rational::operator-=(const int64_t rhs) {
  num_ = num_ - rhs * den_;
  gcd();
  return *this;
}

Rational operator-(const Rational& lhs, const int64_t rhs) {
  Rational ans = lhs;
  ans -= rhs;
  return ans;
}

Rational& Rational::operator*=(const Rational& rhs) {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational ans = lhs;
  ans *= rhs;
  return ans;
}

Rational Rational::operator*=(const int64_t rhs) {
  num_ = num_ * rhs;
  gcd();
  return *this;
}

Rational operator*(const Rational& lhs, const int64_t rhs) {
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
  den_ = den_* rhs;
  gcd();
  return *this;
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  Rational ans = lhs;
  ans /= rhs;
  return ans;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
  return ((lhs.num() == rhs.num()) && (lhs.den() == rhs.den()));
}

bool operator==(const Rational& lhs, const int64_t rhs) {
  return (lhs.num() == rhs * lhs.den());
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
  return((lhs.num() * rhs.den()) >= rhs.num() * lhs.den());
}

bool operator>=(const Rational& lhs, const int64_t rhs) {
  return((lhs.num() >= rhs * lhs.den()));
}

bool operator>(const Rational& lhs, const Rational& rhs) {
  return((lhs.num() * rhs.den()) > rhs.num() * lhs.den());
}

bool operator>(const Rational& lhs, const int64_t rhs) {
  return((lhs.num()) > rhs * lhs.den());
}

bool operator<(const Rational& lhs, const Rational& rhs) {
  return((lhs.num() * rhs.den()) < rhs.num() * lhs.den());
}

bool operator<(const Rational& lhs, const int64_t rhs) {
  return((lhs.num()) < rhs * lhs.den());
}


bool operator<=(const Rational& lhs, const Rational& rhs) {
  return ((lhs.num() * rhs.den()) <= rhs.num() * lhs.den());
}

bool operator<=(const Rational& lhs, const int64_t rhs) {
  return ((lhs.num()) <= rhs * lhs.den());
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
  return !((lhs.num() == rhs.num()) && (lhs.den() == rhs.den()));
}

bool operator!=(const Rational& lhs, const int64_t rhs) {
  return !(lhs.num() == rhs * lhs.den());
}

int64_t Rational::num() const {
  return num_;
}

int64_t Rational::den() const {
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
}
