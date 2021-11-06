#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class ZeroDivisionException: public std::exception{
public:
    const char* what() const noexcept override{
        return "Error: division by zero";
    }
};

class Fraction
{
public:
    Fraction(): numerator(1), denominator(1)
    {}
    Fraction(int p): numerator(p), denominator(1)
    {}
    Fraction(int p, unsigned int q): numerator(p), denominator(q)
    {
        if (denominator == 0) {
            throw ZeroDivisionException();
    }
    ~Fraction()
    {}
    explicit operator double() const
    {
        return double(numerator) / double(denominator);
    }

    void reduce();
    friend std::ostream& operator<< (std::ostream& stream, Fraction& frac);
    friend std::istream& operator>> (std::istream& stream, Fraction& frac);

    friend Fraction operator+ (const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator- (const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator* (const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/ (const Fraction& lhs, const Fraction& rhs);

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    friend bool operator> (const Fraction& lhs, const Fraction& rhs);
    friend bool operator< (const Fraction& lhs, const Fraction& rhs);
    friend bool operator== (const Fraction& lhs, const Fraction& rhs);
    friend bool operator!= (const Fraction& lhs, const Fraction& rhs);
    friend bool operator>= (const Fraction& lhs, const Fraction& rhs);
    friend bool operator<= (const Fraction& lhs, const Fraction& rhs);

    Fraction& operator++();
    Fraction& operator--();

    Fraction operator++(int);
    Fraction operator--(int);

private:
    int numerator;
    unsigned int denominator;
};
