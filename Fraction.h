#pragma once
#include <cmath>
#include <iostream>
#include <ostream>

class Fraction {
    private:
        int numerator;
        int denominator;

        void reduce();

    public:
        Fraction(int numerator = 1, int denominator = 1);
        Fraction(const Fraction &ref);

        [[nodiscard]] int getNumerator() const;
        void setNumerator(int numerator);
        [[nodiscard]] int getDenominator() const;
        void setDenominator(int denominator);
        void set(int numerator, int denominator);
        void set(const Fraction &that);


        friend bool operator== (const Fraction &_this, const Fraction &that);
        friend bool operator<= (const Fraction &_this, const Fraction &that);
        friend bool operator>= (const Fraction &_this, const Fraction &that);
        friend bool operator<  (const Fraction &_this, const Fraction &that);
        friend bool operator>  (const Fraction &_this, const Fraction &that);

        friend Fraction& operator+= (Fraction &_this, const Fraction &that);
        friend Fraction& operator-= (Fraction &_this, const Fraction &that);
        friend Fraction& operator*= (Fraction &_this, const Fraction &that);
        friend Fraction& operator/= (Fraction &_this, const Fraction &that);

        friend Fraction& operator++ (Fraction &_this);
        friend Fraction& operator-- (Fraction &_this);
        friend Fraction  operator++ (Fraction &_this, int x);
        friend Fraction  operator-- (Fraction &_this, int x);

        friend Fraction  operator+  (const Fraction &_this, const Fraction &that);
        friend Fraction  operator-  (const Fraction &_this, const Fraction &that);
        friend Fraction  operator*  (const Fraction &_this, const Fraction &that);
        friend Fraction  operator/  (const Fraction &_this, const Fraction &that);

        friend Fraction  operator~  (const Fraction &_this);
        friend std::ostream& operator<<(std::ostream &os, const Fraction &fraction);
        friend std::istream& operator>>(std::istream &is, Fraction &fraction);
};

