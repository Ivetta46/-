#include "Figures.h"
#include <cmath>

bool Triangle::check(double a, double b, double c)
{
    if ((a + b < c) || (a + c < b) || (b + c < a))
        return false;
    return true;
}

double Triangle::getPerimeter() const
{
    double p = 0;
    for (auto i = 0; i < 3; i++)
        p += Sides[i];
    return p;
}

double Triangle::getSquare() const
{

    double p = getPerimeter() * 0.5;
    double a = double(p - Sides[0]);
    double b = double(p - Sides[1]);
    double c = double(p - Sides[2]);

    a = double(a * p);
    a = double(b * a);
    a = double(c * a);

    double s = pow(a, 0.5);
    return s;
}

void Triangle::getInformation() const
{
    std::cout << "Name of figure: Triangle.\n";
    std::cout << "Lines are " << Sides[0] << ", " << Sides[1] << ", " << Sides[2] << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}

