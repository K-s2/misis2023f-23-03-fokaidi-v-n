#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <rational/rational.hpp>
#include "doctest.h"
#include <stdexcept>
#include <cstdint>


TEST_CASE("rational assignment test") {
  Rational a;
  CHECK(0 == a.num());
  CHECK(1 == a.den());

  a = Rational(4, 5);
  CHECK(4 == a.num());
  CHECK(5 == a.den());

  a = Rational(9, 3);
  CHECK(3 == a.num());
  CHECK(1 == a.den());

  a = Rational(123, 987);
  CHECK(41 == a.num());
  CHECK(329 == a.den());

  a = Rational(21474883647, 22000000000);
  CHECK(21474883647 == a.num());
  CHECK(22000000000 == a.den());

  a = Rational(-21474883647, -22000000000);
  CHECK(21474883647 == a.num());
  CHECK(22000000000 == a.den());

  a = Rational(-21474883647, 22000000000);
  CHECK(-21474883647 == a.num());
  CHECK(22000000000 == a.den());

  a = Rational(21474883647, -22000000000);
  CHECK(-21474883647 == a.num());
  CHECK(22000000000 == a.den());

  a = Rational(0, -123);
  CHECK(0 == a.num());
  CHECK(1 == a.den());
}


TEST_CASE("rational copy test") {
  Rational a(3, 5);
  Rational b(a);
  CHECK(3 == b.num());
  CHECK(5 == b.den());

  a = Rational(4, 5);
  b = Rational(1, 2);
  Rational c(b);
  c = a;
  CHECK(4 == c.num());
  CHECK(5 == c.den());
}


TEST_CASE("rational == test") {
  Rational a(3, 5);
  Rational b;
  Rational c;
  CHECK(0 == (a == b));
  CHECK(0 == (a == c));
  CHECK(1 == (b == c));

  b = Rational(3, 5);
  c = Rational(-3, 5);
  CHECK(1 == (a == b));
  CHECK(0 == (a == c));

  b = Rational(-3, -5);
  CHECK(0 == (b == c));
  CHECK(1 == (b == a));

  a = Rational(-1234, 4321);
  b = Rational(-1234, -4321);
  CHECK(0 == (a == b));

}


TEST_CASE("rational != test") {
  Rational a;
  CHECK(1 == (a != Rational(1)));
  CHECK(1 == (a == Rational(0)));

  a = Rational(4, 5);
  Rational b(a);
  Rational c(-4, -5);
  Rational d(-4, 5);
  CHECK(0 == (a != b));
  CHECK(0 == (a != c));
  CHECK(1 == (a != d));
  CHECK(1 == (c != d));
}


TEST_CASE("rational >  >= < <= tests") {
  Rational a(1, 2);
  Rational b(3, 4);
  CHECK(1 == (b >= a));
  CHECK(0 == (b <= a));
  CHECK(0 == (a > b));
  CHECK(1 == (a < b));
  CHECK(0 == (b < a));
  CHECK(1 == (b > a));

  a = Rational(-1, 2);
  b = Rational(1, 2);
  CHECK(1 == (b >= a));
  CHECK(0 == (b <= a));
  CHECK(0 == (a > b));
  CHECK(1 == (a < b));
  CHECK(0 == (b < a));
  CHECK(1 == (b > a));

  a = Rational(-1, 2);
  b = Rational(-1, -2);
  CHECK(1 == (b >= a));
  CHECK(0 == (b <= a));
  CHECK(0 == (a > b));
  CHECK(1 == (a < b));
  CHECK(0 == (b < a));
  CHECK(1 == (b > a));

  a = Rational(1, 2);
  b = Rational(1, 2);
  CHECK(1 == (b >= a));
  CHECK(1 == (b <= a));
  CHECK(0 == (a > b));
  CHECK(0 == (a < b));
  CHECK(0 == (b < a));
  CHECK(0 == (b > a));

  a = Rational(0);
  b = Rational(-1, 1000);
  CHECK(0 == (b >= a));
  CHECK(1 == (b <= a));
  CHECK(1 == (a > b));
  CHECK(0 == (a < b));
  CHECK(1 == (b < a));
  CHECK(0 == (b > a));
}


TEST_CASE("rational += test") {
  Rational a;
  Rational b;
  a += Rational(1);
  CHECK(1 == a.num());
  CHECK(1 == a.den());

  a = Rational(1);
  b = Rational(2);
  a += b;
  CHECK(3 == a.num());

  a = Rational(-1);
  b = Rational(1);
  a += b;
  CHECK(0 == a.num());

  a = Rational(-1, -1);
  b = Rational(-1);
  a += b;
  CHECK(0 == a.num());

  a = Rational(1);
  b = Rational(-1);
  a += b;
  CHECK(0 == a.num());

  a = Rational(-4, 3);
  b = Rational(-1);
  a += b;
  CHECK(-7 == a.num());

  a = Rational(-123, 321);
  b = Rational(-321, -123);
  a += b;
  CHECK(9768 == a.num());
  CHECK(4387 == a.den());

  a = Rational(3, 4);
  b = Rational(7, 12);
  a += b;
  CHECK(4 == a.num());
  CHECK(3 == a.den());

  a = Rational(2, 3);
  b = Rational(-1, 2);
  a += b;
  CHECK(1 == a.num());
  CHECK(6 == a.den());

}


TEST_CASE("rational -= test") {
  Rational a;
  Rational b;

  a = Rational(1);
  b = Rational(2);
  a -= b;
  CHECK(-1 == a.num());

  a = Rational(3);
  b = Rational(2);
  a -= b;
  CHECK(1 == a.num());

  a = Rational(1, 2);
  b = Rational(321, 432);
  a -= b;
  CHECK(-35 == a.num());
  CHECK(144 == a.den());

  a = Rational(-7, -5);
  b = Rational(5, 3 * 123);
  a -= b;
  CHECK(2558 == a.num());
  CHECK(1845 == a.den());

  a = Rational(23, -76);
  b = Rational(54, -43);
  a -= b;
  CHECK(3115 == a.num());
  CHECK(3268 == a.den());

  a = Rational(-23, 15);
  b = Rational(34);
  a -= b;
  CHECK(-533 == a.num());
  CHECK(15 == a.den());
}


TEST_CASE("rational *= test") {
  Rational a;
  Rational b;
  a *= b;
  CHECK(0 == a.num());
  CHECK(1 == a.den());

  a = Rational(123, 2);
  b = Rational(2);
  a *= b;
  CHECK(123 == a.num());
  CHECK(1 == a.den());

  a = Rational(123, 2);
  b = Rational(2, 5);
  a *= b;
  CHECK(123 == a.num());
  CHECK(5 == a.den());

  a = Rational(123, 321);
  b = Rational(321, 123);
  a *= b;
  CHECK(1 == a.num());
  CHECK(1 == a.den());

  a = Rational(-5, 12);
  b = Rational(-9, -2);
  a *= b;
  CHECK(-15 == a.num());
  CHECK(8 == a.den());

  a = Rational(43, -3);
  b = Rational(54, -2);
  a *= b;
  CHECK(387 == a.num());
  CHECK(1 == a.den());

  a = Rational(6, 13);
  b = Rational(0);
  a *= b;
  CHECK(0 == a.num());
  CHECK(1 == a.den());

  a = Rational(45, -76);
  b = Rational(-2, -8);
  a *= b;
  CHECK(-45 == a.num());
  CHECK(304 == a.den());

  a = Rational(5, 7);
  b = Rational(3, 10);
  a *= b;
  CHECK(3 == a.num());
  CHECK(14 == a.den());
}


TEST_CASE("rational /= test") {
  Rational a;
  Rational b;

  a = Rational(3, 4);
  b = Rational(4, 3);
  a /= b;
  CHECK(9 == a.num());
  CHECK(16 == a.den());

  a = Rational(7, 3);
  b = Rational(6, 31);
  a /= b;
  CHECK(217 == a.num());
  CHECK(18 == a.den());

  a = Rational(3, 14);
  b = Rational(7, 4);
  a /= b;
  CHECK(6 == a.num());
  CHECK(49 == a.den());

  a = Rational(12, -13);
  b = Rational(14, -15);
  a /= b;
  CHECK(90 == a.num());
  CHECK(91 == a.den());

  a = Rational(-12, -13);
  b = Rational(14, -15);
  a /= b;
  CHECK(-90 == a.num());
  CHECK(91 == a.den());

  a = Rational(12, -13);
  b = Rational(-14, -15);
  a /= b;
  CHECK(-90 == a.num());
  CHECK(91 == a.den());

  a = Rational(-12, 13);
  b = Rational(14, -15);
  a /= b;
  CHECK(90 == a.num());
  CHECK(91 == a.den());

  a = Rational(986, 543);
  b = Rational(13, 2345);
  a /= b;
  CHECK(2312170 == a.num());
  CHECK(7059 == a.den());

}


TEST_CASE("rational + test") {
  Rational a;
  Rational b;
  Rational c;
  c = a + b;
  CHECK(0 == c.num());
  CHECK(1 == c.den());

  a = Rational(1);
  b = Rational(2);
  c = a + b;
  CHECK(3 == c.num());
  CHECK(1 == c.den());

  a = Rational(4);
  b = Rational(-2);
  c = a + b;
  CHECK(2 == c.num());
  CHECK(1 == c.den());

  a = Rational(3, 4);
  b = Rational(7, 2);
  c = a + b;
  CHECK(17 == c.num());
  CHECK(4 == c.den());

  a = Rational(-5, -4);
  b = Rational(-5, 3);
  c = a + b;
  CHECK(-5 == c.num());
  CHECK(12 == c.den());

  a = Rational(2, 3);
  b = Rational(6, -7);
  c = a + b;
  CHECK(-4 == c.num());
  CHECK(21 == c.den());

  a = Rational(123, 23);
  b = Rational(-234, 6);
  c = a + b;
  CHECK(-774 == c.num());
  CHECK(23 == c.den());

  a = Rational(7, 15);
  b = Rational(-4, -81);
  c = a + b;
  CHECK(209 == c.num());
  CHECK(405 == c.den());
}


TEST_CASE("rational - test") {
  Rational a;
  Rational b;
  Rational c;
  c = a - b;
  CHECK(0 == c.num());
  CHECK(1 == c.den());

  a = Rational(1);
  b = Rational(2);
  c = a - b;
  CHECK(-1 == c.num());
  CHECK(1 == c.den());

  a = Rational(4);
  b = Rational(-2);
  c = a - b;
  CHECK(6 == c.num());
  CHECK(1 == c.den());

  a = Rational(3, 4);
  b = Rational(7, 2);
  c = a - b;
  CHECK(-11 == c.num());
  CHECK(4 == c.den());

  a = Rational(-5, -4);
  b = Rational(-5, 3);
  c = a - b;
  CHECK(35 == c.num());
  CHECK(12 == c.den());

  a = Rational(2, 3);
  b = Rational(6, -7);
  c = a - b;
  CHECK(32 == c.num());
  CHECK(21 == c.den());

  a = Rational(123, 23);
  b = Rational(-234, 6);
  c = a - b;
  CHECK(1020 == c.num());
  CHECK(23 == c.den());

  a = Rational(7, 15);
  b = Rational(-4, -81);
  c = a - b;
  CHECK(169 == c.num());
  CHECK(405 == c.den());
}


TEST_CASE("rational * test") {
  Rational a;
  Rational b;
  Rational c;
  c = a * b;
  CHECK(0 == c.num());
  CHECK(1 == c.den());

  a = Rational(123, 2);
  b = Rational(2);
  c = a * b;
  CHECK(123 == c.num());
  CHECK(1 == c.den());

  a = Rational(123, 2);
  b = Rational(2, 5);
  c = a * b;
  CHECK(123 == c.num());
  CHECK(5 == c.den());

  a = Rational(123, 321);
  b = Rational(321, 123);
  c = a * b;
  CHECK(1 == c.num());
  CHECK(1 == c.den());

  a = Rational(-5, 12);
  b = Rational(-9, -2);
  c = a * b;
  CHECK(-15 == c.num());
  CHECK(8 == c.den());

  a = Rational(43, -3);
  b = Rational(54, -2);
  c = a * b;
  CHECK(387 == c.num());
  CHECK(1 == c.den());

  a = Rational(6, 13);
  b = Rational(0);
  c = a * b;
  CHECK(0 == c.num());
  CHECK(1 == c.den());

  a = Rational(45, -76);
  b = Rational(-2, -8);
  c = a * b;
  CHECK(-45 == c.num());
  CHECK(304 == c.den());

  a = Rational(5, 7);
  b = Rational(3, 10);
  c = a * b;
  CHECK(3 == c.num());
  CHECK(14 == c.den());
}

TEST_CASE("rational = test") {
  Rational a;
  Rational b;
  a = Rational(1, 2);
  b = Rational(2, 3);
  a = b;
  CHECK(2 == a.num());
  a -= 1;
  CHECK(2 == b.num());
}

TEST_CASE("rational unarni operator minus") {
  Rational a;
  Rational b;
  a = Rational(1, 2);
  b = -a;
  CHECK((b.num() == -1));
  CHECK(b.den() == 2);
}

TEST_CASE("rational / test") {
  Rational a;
  Rational b;
  Rational c;

  a = Rational(1);
  b = Rational(2);
  c = a / b;
  CHECK(1 == c.num());
  CHECK(2 == c.den());

  a = Rational(4);
  b = Rational(-2);
  c = a / b;
  CHECK(-2 == c.num());
  CHECK(1 == c.den());

  a = Rational(3, 4);
  b = Rational(7, 2);
  c = a / b;
  CHECK(3 == c.num());
  CHECK(14 == c.den());

  a = Rational(-5, -4);
  b = Rational(-5, 3);
  c = a / b;
  CHECK(-3 == c.num());
  CHECK(4 == c.den());

  a = Rational(2, 3);
  b = Rational(6, -7);
  c = a / b;
  CHECK(-7 == c.num());
  CHECK(9 == c.den());

  a = Rational(123, 23);
  b = Rational(-234, 6);
  c = a / b;
  CHECK(-41 == c.num());
  CHECK(299 == c.den());

  a = Rational(7, 15);
  b = Rational(-4, -81);
  c = a / b;
  CHECK(189 == c.num());
  CHECK(20 == c.den());
}


TEST_CASE("exceptions test") {
  CHECK_THROWS(Rational(1, 0));
  CHECK_THROWS(Rational(1, 2) / Rational(0, 4));
  CHECK_THROWS(Rational(1, 0) * Rational(3, 0));
}


