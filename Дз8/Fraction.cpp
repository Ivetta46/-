#include "Fraction.hpp"

int alg_euclid(int a, int b)
{
    if (b == 0) return a;
    return alg_euclid(b, a % b);
}

void Fraction::reduce()
{
    int gcd;
    gcd = alg_euclid(abs(numerator), denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

std::ostream& operator<< (std::ostream& stream, Fraction& frac)
{
    stream << frac.numerator << '/' << frac.denominator;
    return stream;
}

std::istream& operator>> (std::istream& stream, Fraction& frac)
{
    stream >> frac.numerator;
    stream >> frac.denominator;
    return stream;
}

Fraction operator+ (const Fraction& lhs, const Fraction& rhs)
{
    Fraction result;
    result.numerator = lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator;
    result.denominator = lhs.denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction operator- (const Fraction& lhs, const Fraction& rhs)
{
    Fraction result;
    result.numerator = lhs.numerator * rhs.denominator - lhs.denominator * rhs.numerator;
    result.denominator = lhs.denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction operator* (const Fraction& lhs, const Fraction& rhs)
{
    Fraction result;
    result.numerator = lhs.numerator * rhs.numerator;
    result.denominator = lhs.denominator * rhs.denominator;
    result.reduce();
    return result;
}

Fraction operator/ (const Fraction& lhs, const Fraction& rhs)
{
    Fraction result;
    int sign = rhs.numerator / abs(rhs.numerator);
    result.numerator = lhs.numerator * rhs.denominator * sign;
    result.denominator = lhs.denominator * abs(rhs.numerator);
    result.reduce();
    return result;
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    numerator = numerator * other.denominator + denominator * other.numerator;
    denominator = denominator * other.denominator;
    this->reduce();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
    numerator = numerator * other.denominator - denominator * other.numerator;
    denominator = denominator * other.denominator;
    this->reduce();
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
    numerator = numerator * other.numerator;
    denominator = denominator * other.denominator;
    this->reduce();
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{

    int sign = other.numerator / abs(other.numerator);
    numerator = numerator * other.denominator*sign;
    denominator = denominator * abs(other.numerator);
    this->reduce();
    return *this;
}

bool operator> (const Fraction& lhs, const Fraction& rhs)
{
    int left = lhs.numerator * rhs.denominator;
    int right = rhs.numerator * lhs.denominator;
    return left > right;
}

bool operator< (const Fraction& lhs, const Fraction& rhs)
{
    int left = lhs.numerator * rhs.denominator;
    int right = rhs.numerator * lhs.denominator;
    return left < right;
}

bool operator== (const Fraction& lhs, const Fraction& rhs)
{
    int left = lhs.numerator * rhs.denominator;
    int right = rhs.numerator * lhs.denominator;
    return left == right;
}

bool operator!= (const Fraction& lhs, const Fraction& rhs)
{
    int left = lhs.numerator * rhs.denominator;
    int right = rhs.numerator * lhs.denominator;
    return left != right;
}

bool operator>= (const Fraction& lhs, const Fraction& rhs)
{
    int left = lhs.numerator * rhs.denominator;
    int right = rhs.numerator * lhs.denominator;
    return left >= right;
}

bool operator<= (const Fraction& lhs, const Fraction& rhs)
{
    int left = lhs.numerator * rhs.denominator;
    int right = rhs.numerator * lhs.denominator;
    return left <= right;
}

Fraction& Fraction::operator++()
{
    ++numerator;
    return *this;
}

Fraction& Fraction::operator--()
{
    --numerator;
    return *this;
}

Fraction Fraction::operator++(int)
{
    Fraction temp(numerator, denominator);
    ++(*this);
    return temp;
}

Fraction Fraction::operator--(int) {
    Fraction temp(numerator, denominator);
    --(*this);
    return temp;
}

