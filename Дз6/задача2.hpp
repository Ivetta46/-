#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Fraction
{
public:
	Fraction(): numerator(1), denominator(1)
	{}
	Fraction(int p): numerator(p), denominator(1)
	{}
	Fraction(int p, unsigned int q): numerator(p), denominator(q)
	{}
	
	// Конструктор копирования
	Fraction(const Fraction& x)
	{
		*denominator = *x.denominator;
		*numerator = *x.numerator;
	}
 
	// Оператор присваивания копированием
	Fraction& operator=(const Fraction& x)
	{
		if (&x == this)
			return *this;

		*denominator = *x.denominator;
		*numerator = *x.numerator;
 
		return *this;
	}
	
	// Конструктор перемещения
	Fraction(Fraction&& x)
		: numerator(x.numerator)
		: denominator(x.denominator)
	{
		x.numerator = nullptr; 
	        x.denominator = nullptr;
	}
 
	// Оператор присваивания копированием
	Fraction& operator=(const Fraction& x)
	{
		if (&x == this)
			return *this;
 
		*denominator = *x.denominator;
		*numerator = *x.numerator;
 
		return *this;
	}
 
	// Оператор присваивания перемещением
	Fraction& operator=(Fraction&& x)
	{
		if (&x == this)
			return *this;
 
		numerator = x.numerator;
		x.numerator = nullptr; 
		denominator = x.denominator;
		x.denominator = nullptr; 
		
		return *this;
	}
	
	~Fraction()
	{}
	explicit operator double() const
	{
		return double(numerator) / double(denominator);
	}
	SmartPtr(const SmartPtr& another) : m_ptr(another.m_ptr) {}

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
	void reduce();
};
