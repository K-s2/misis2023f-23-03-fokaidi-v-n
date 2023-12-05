#include <sstream>
#include <iostream>

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
    num_ = num_/gcd_;
    den_ = den_/gcd_;
  }


  static const char separator_slash{ '/' };

};



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
