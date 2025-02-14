#pragma once
#include <numeric>
#include <cstdlib>
#include <iostream>

class Rational {
 private:
    int numerator_{0};
    int denominator_{1};
    void Reduction() {
        const int divider = std::gcd(numerator_, denominator_);
        numerator_ /= divider;
        denominator_ /= divider;
        if (denominator_ < 0) {
            numerator_ *= -1;
            denominator_ *= -1;
        }
    }

 public:
    Rational() = default;

    Rational(int num) : numerator_(num), denominator_(1) {}

    Rational(int num, int den) : numerator_(num), denominator_(den) {
        Reduction();
    }

    Rational(const Rational& other) {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
    }

    Rational operator+(const Rational& other) const {
        Rational new_r = *this;
        new_r += other;
        return new_r;
    }

    Rational operator-(const Rational& other) const {
        Rational new_r = *this;
        new_r -= other;
        return new_r;
    }

    Rational operator*(const Rational& other) const {
        Rational new_r = *this;
        new_r *= other;
        return new_r;
    }

    Rational operator/(const Rational& other) const {
        Rational new_r = *this;
        new_r /= other;
        return new_r;
    }

    Rational& operator+=(const Rational& other) {
        numerator_ = numerator_ * other.denominator_ + denominator_ * other.numerator_;
        denominator_ *= other.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator-=(const Rational& other)  {
        numerator_ = numerator_ * other.denominator_ - denominator_ * other.numerator_;
        denominator_ *= other.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        numerator_ *= other.numerator_;
        denominator_ *= other.denominator_;
        Reduction();
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        numerator_ *= other.denominator_;
        denominator_ *= other.numerator_;
        Reduction();
        return *this;
    }

    Rational& operator=(const Rational& other) {
        numerator_ = other.numerator_;
        denominator_ = other.denominator_;
        return *this;
    }

    Rational operator+() const {
        return *this;
    }

    Rational operator-() const {
        Rational new_r = *this;
        new_r.numerator_ *= -1;
        return new_r;
    }

    Rational Inv() const {
        if (numerator_ == 0) std::abort();
        return Rational(denominator_, numerator_);
    }

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }
};


inline auto operator<=>(const Rational& l, const Rational& r) {
    return
        (static_cast<int64_t>(l.GetNumerator()) * r.GetDenominator())
        <=>
        (static_cast<int64_t>(r.GetNumerator()) * l.GetDenominator());
}

inline bool operator==(const Rational& l, const Rational& r) {
    return
        (static_cast<int64_t>(l.GetNumerator()) * r.GetDenominator())
        ==
        (static_cast<int64_t>(r.GetNumerator()) * l.GetDenominator());
}

inline std::ostream& operator<<(std::ostream& out, const Rational& r) {
    out << r.GetNumerator();
    if (r.GetDenominator() != 1)  {
        out << " / " << r.GetDenominator();
    }
    return out;
}

inline std::istream& operator>>(std::istream& in, Rational& r) {
    int a, b;
    char oper;
    in >> a;
    if (in.fail()) return in;
    in >> oper;
    if (in.fail() || oper != '/') {
        r = Rational(a);
        return in;
    }
    in >> b;
    if (in.fail()) return in;
    if (b == 0) {
        in.setstate(std::ios::failbit);
        return in;
    }
    r = Rational(a, b);
    return in;
}

