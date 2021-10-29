#include "Figures.h"

double Circle::getPerimeter() const
{
    return 2 * 3.14 * r;
}

double Circle::getSquare() const
{
    return 3.14 * r * r;
}

void Circle::getInformation() const
{
    std::cout << "Name of figure: Circle.\n";
    std::cout << "Radius is " << r << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}


