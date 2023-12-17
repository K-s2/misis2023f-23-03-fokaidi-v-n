#include "complex.hpp"

static const double epsilon = 2 * std::numeric_limits<double>::epsilon();

Complex::Complex() : re(0.0), im(0.0) {}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {}

Complex::Complex(const double real) : re(real), im(0.0) {}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

Complex& Complex::operator=(const Complex& other) {
  re = other.re;
  im = other.im;
  return *this;
}

Complex Complex::operator-() const noexcept {
  return Complex(-re, -im);
}

bool Complex::operator==(const Complex& rhs) const noexcept {
  return (std::abs(re - rhs.re) < epsilon) && (std::abs(im - rhs.im) < epsilon);
}
bool operator==(const Complex& lhs, const double rhs) {
  return lhs == Complex(rhs);
}
bool operator==(const double lhs, const Complex& rhs) {
  return Complex(lhs) == rhs;
}

bool Complex::operator!=(const Complex& rhs) const noexcept {
  return !(*this == rhs);
}
bool operator!=(const Complex& lhs, const double rhs) {
  return lhs != Complex(rhs);
}
bool operator!=(const double lhs, const Complex& rhs) {
  return Complex(lhs) != rhs;
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
  re += rhs.re;
  im += rhs.im;
  return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept {
  re += rhs;
  return *this;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept {
  re -= rhs;
  return *this;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
  double tempRe = re * rhs.re - im * rhs.im;
  double tempIm = re * rhs.im + im * rhs.re;
  re = tempRe;
  im = tempIm;
  return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (std::abs(denominator) > epsilon) {
    double resultReal = (re * rhs.re + im * rhs.im) / denominator;
    double resultImag = (im * rhs.re - re * rhs.im) / denominator;

    re = resultReal;
    im = resultImag;
    return *this;
  }
  throw std::overflow_error("Divide by zero exception");
}
Complex& Complex::operator/=(const double rhs) {
  if (std::abs(rhs) > epsilon) {
    re /= rhs;
    im /= rhs;
    return *this;
  }
  throw std::overflow_error("Divide by zero exception");
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}
Complex operator+(const Complex& lhs, const double rhs) noexcept {
  return Complex(lhs.re + rhs, lhs.im);
}
Complex operator+(const double lhs, const Complex& rhs) noexcept {
  return Complex(rhs.re + lhs, rhs.im);
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}
Complex operator-(const Complex& lhs, const double rhs) noexcept {
  return Complex(lhs.re - rhs, lhs.im);
}
Complex operator-(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs - rhs.re, -rhs.im);
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(
    lhs.re * rhs.re - lhs.im * rhs.im,
    lhs.re * rhs.im + lhs.im * rhs.re
  );
}
Complex operator*(const Complex& lhs, const double rhs) noexcept {
  return Complex(lhs.re * rhs, lhs.im * rhs);
}
Complex operator*(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs * rhs.re, lhs * rhs.im);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (std::abs(denominator) > epsilon) {
    return Complex(
      (lhs.re * rhs.re + lhs.im * rhs.im) / denominator,
      (lhs.im * rhs.re - lhs.re * rhs.im) / denominator
    );
  }
  throw std::overflow_error("Divide by zero exception");
}
Complex operator/(const Complex& lhs, const double rhs) {
  if (std::abs(rhs) > epsilon) {
    return Complex(lhs.re / rhs, lhs.im / rhs);
  }
  throw std::overflow_error("Divide by zero exception");
}
Complex operator/(const double lhs, const Complex& rhs) {
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (std::abs(denominator) > epsilon) {
    return Complex(
      (lhs * rhs.re) / denominator,
      (-lhs * rhs.im) / denominator
    );
  }
  throw std::overflow_error("Divide by zero exception");
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
  ostrm << leftBrace << re << separator << im << rightBrace;
  return ostrm;
}
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char rightBrace(0);
  istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
  if (istrm.good() || istrm.eof())
  {
    if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
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

