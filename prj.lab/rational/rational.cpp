#include <rational/rational.hpp>


Rational::Rational() : num_(0), den_(1) {}

Rational::Rational(const int64_t numerator) : num_(numerator), den_(1) {}

Rational::Rational(const int64_t numerator, const int64_t denumerator) : num_(numerator), den_(denumerator) {}

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

Rational& Rational::operator+=(const int64_t rhs) {
  num_ = num_ + den_ * rhs;
  gcd();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
  num_ = num_ * rhs.den_ - den_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational& Rational::operator-=(const int64_t rhs) {
  num_ = num_ - rhs * den_;
  gcd();
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  num_ = num_ * rhs.num_;
  den_ = den_ * rhs.den_;
  gcd();
  return *this;
}

Rational Rational::operator*=(const int64_t rhs) {
  num_ = num_ * rhs;
  gcd();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  num_ = num_ * rhs.den_;
  den_ = den_ * rhs.num_;
  gcd();
  return *this;
}

Rational& Rational::operator/=(const int64_t rhs) {
  den_ = den_* rhs;
  gcd();
  return *this;
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
