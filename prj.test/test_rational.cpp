#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.hpp>

TEST_CASE("Test rational operations") {
    SUBCASE("Addition") {
        CHECK(Rational(1,2) + Rational(1,4) == Rational(3,4));
        CHECK(Rational(2,3) + 1 == Rational(5,3));
    }

    SUBCASE("Subtraction") {
        CHECK(Rational(1,2) - Rational(1,4) == Rational(1,4));
        CHECK(Rational(2,3) - 1 == Rational(-1,3));
    }

    SUBCASE("Multiplication") {
        CHECK(Rational(1,2) * Rational(1,4) == Rational(1,8));
        CHECK(Rational(2,3) * -2 == Rational(-4,3));
    }

    SUBCASE("Division") {
        CHECK(Rational(1,2) / Rational(1,4) == Rational(2));
        CHECK(Rational(2,3) / -2 == Rational(-1,3));
    }

    SUBCASE("Equality") {
        CHECK(Rational(1,2) == Rational(1,2));
        CHECK(Rational(1) == 1);
    }

    SUBCASE("Comparison") {
        CHECK(Rational(1,2) < Rational(3,4));
        CHECK(Rational(3,4) > -1);
    }
}
