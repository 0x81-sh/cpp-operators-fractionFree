#include "Fraction.h"

int gcd (int a, int b) {
    if (a == b) return a;

    if (a > b) {
        return gcd(a - b, b);
    } else {
        return gcd(b - a, a);
    }
}

int lcm (int a, int b) {
    return abs(a / gcd(a, b) * b);
}

// ---------------------------------------

void Fraction::reduce() {
    int gcdV = gcd(abs(numerator), denominator);
    if (gcdV == 1) return;

    numerator /= gcdV;
    denominator /= gcdV;
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    reduce();
}

Fraction::Fraction(const Fraction &ref) {
    set(ref);
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    this->numerator = numerator;
    reduce();
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    this->denominator = denominator;
    reduce();
}

void Fraction::set(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

void Fraction::set(const Fraction &that) {
    numerator = that.numerator;
    denominator = that.denominator;
}

// ---------------------------------------

Fraction operator+(const Fraction &_this, const Fraction &that) {
    int lcmV = lcm(_this.denominator, that.denominator);
    return {(_this.numerator * lcmV / _this.denominator) + (that.numerator * lcmV / that.denominator), lcmV};
}

Fraction operator-(const Fraction &_this, const Fraction &that) {
    int lcmV = lcm(_this.denominator, that.denominator);
    return {(_this.numerator * lcmV / _this.denominator) - (that.numerator * lcmV / that.denominator), lcmV};
}

Fraction operator*(const Fraction &_this, const Fraction &that) {
    return {_this.numerator * that.numerator, _this.denominator * that.denominator};
}

Fraction operator/(const Fraction &_this, const Fraction &that) {
    return {_this.numerator * that.denominator, _this.denominator * that.numerator};
}

bool operator==(const Fraction &_this, const Fraction &that) {
    return _this.denominator == that.denominator && _this.numerator == that.numerator;
}

bool operator<(const Fraction &_this, const Fraction &that) {
    int lcmV = lcm(_this.denominator, that.denominator);
    return (_this.numerator * lcmV / _this.denominator) < (that.numerator * lcmV / that.denominator);
}

bool operator>(const Fraction &_this, const Fraction &that) {
    return !(_this <= that);
}

bool operator<=(const Fraction &_this, const Fraction &that) {
    int lcmV = lcm(_this.denominator, that.denominator);
    return (_this.numerator * lcmV / _this.denominator) <= (that.numerator * lcmV / that.denominator);
}

bool operator>=(const Fraction &_this, const Fraction &that) {
    return !(_this < that);
}

Fraction operator~(const Fraction &_this) {
    return {_this.denominator, _this.numerator};
}

Fraction& operator++(Fraction &_this) {
    _this.numerator += _this.denominator;
    return _this;
}

Fraction& operator--(Fraction &_this) {
    _this.numerator -= _this.denominator;
    return _this;
}

Fraction operator++(Fraction &_this, int x) {
    Fraction res(_this.numerator + _this.denominator, _this.denominator);
    _this.numerator += _this.denominator;

    return res;
}

Fraction operator--(Fraction &_this, int x) {
    Fraction res(_this.numerator - _this.denominator, _this.denominator);
    _this.numerator -= _this.denominator;

    return res;
}

Fraction& operator+=(Fraction &_this, const Fraction &that) {
    _this.set(_this + that);
    return _this;
}

Fraction& operator-=(Fraction &_this, const Fraction &that) {
    _this.set(_this - that);
    return _this;
}

Fraction& operator*=(Fraction &_this, const Fraction &that) {
    _this.set(_this * that);
    return _this;
}

Fraction& operator/=(Fraction &_this, const Fraction &that) {
    _this.set(_this / that);
    return _this;
}

std::ostream& operator<<(std::ostream &os, const Fraction &fraction) {
    os << "[" << fraction.numerator << "/" << fraction.denominator << "]";
    return os;
}

std::istream& operator>>(std::istream &is, Fraction &fraction) {
    std::cout << "Numerator:";
    is >> fraction.numerator;
    std::cout << " Denominator:";
    is >> fraction.denominator;
    return is;
}
