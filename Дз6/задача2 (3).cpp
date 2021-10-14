#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Fraction.hpp"

int main()
{
	Fraction frac1(8,9);
	std::cout << frac1 << '\n';
	Fraction frac2;
	std::cin >> frac2;
	std::cout << frac2 << '\n';
	std::cout << double(frac2) << '\n';
	Fraction frac3 = frac1 + frac2;
	std::cout <<"Addition test " << frac3 << '\n';
	frac3 = frac1 - frac2;
	std::cout << "Subtraction test " << frac3 << '\n';
	frac3 = frac1 * frac2;
	std::cout << "Multiplication test " << frac3 << '\n';
	frac3 = frac1 / frac2;
	std::cout << "Division test " << frac3 << '\n';
	frac1 += frac2;
	std::cout << "+= test " << frac1 << '\n';
	frac1 -= frac2;
	std::cout << "-= test " << frac1 << '\n';
	frac1 *= frac2;
	std::cout << "*= test " << frac1 << '\n';
	frac1 /= frac2;
	std::cout << "/= test " << frac1 << '\n';
	std::cout << (frac1 > frac2) << '\n';
	std::cout << (frac1 < frac2) << '\n';
	std::cout << (frac1 == frac2) << '\n';
	std::cout << (frac1 != frac2) << '\n';
	std::cout << (frac1 >= frac2) << '\n';
	std::cout << (frac1 <= frac2) << '\n';

	Fraction frac4(5, 11);
	Fraction frac5 = frac4;

	std::cout << frac4 << " " << frac5 << std::endl;
	std::cout << ++frac4 << " " << --frac5 << std::endl;
	std::cout << frac4 << " " << frac5 << std::endl;

	Fraction frac6 = frac4++;
	Fraction frac7 = frac5--;

	std::cout << frac6 << " " << frac7 << std::endl;
	std::cout << frac4 << " " << frac5 << std::endl;

	return 0;
}