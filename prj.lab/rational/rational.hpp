#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <sstream>

class Rational {

public:
  //конструктор по умолчанию
  Rational() : num_(0), den_(1) {}
  //конструктор по умолчанию с одним аргументом
  Rational(const int64_t numerator) : num_(numerator), den_(1) {}
  //конструктор с двумя аргументами
  Rational(const int64_t numerator, const int64_t denumerator) : num_(numerator), den_(denumerator) {}

  //определим функции для записи и чтения
  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);

  //определим перегруженныф оператор +=
  Rational& operator+=(const Rational& rhs) {
    num_ = num_ * rhs.den_ + den_ * rhs.num_;
    den_ = den_ * rhs.den_;
    gcd();
    return *this;
  }

  Rational& operator-=(const Rational& rhs) {
    num_ = num_ * rhs.den_ - den_ * rhs.num_;
    den_ = den_ * rhs.den_;
    gcd();
    return *this;
  }

  Rational& operator*=(const Rational& rhs) {
    num_ = num_ * rhs.num_;
    den_ = den_ * rhs.den_;
    gcd();
    return *this;
  }

  Rational& operator/=(const Rational& rhs) {
    num_ = num_ * rhs.den_;
    den_ = den_ * rhs.num_;
    gcd();
    return *this;
  }

  int64_t num() const { return num_; }
  int64_t den() const { return den_; }

private:
  int64_t num_ = 0;
  int64_t den_ = 1;
  int num_gcd(int64_t a, int64_t b) {
    if (b == 0) {
      return a;
    }
    return num_gcd(b, a % b);
  }

  void gcd() {
    int64_t gcd_ = num_gcd(num_, den_);
    num_ = num_ / gcd_;
    den_ = den_ / gcd_;
  }


  static const char separator_slash{ '/' };

};


Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);

bool operator!=(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

inline std::istream& operator>>(std::istream& istrm, Rational& rhs);

#endif
