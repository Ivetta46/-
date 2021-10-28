#include "Figures.h"

double circle::getPerimeter() const
{
    return 2 * 3.14 * r;
}

double circle::getSquare() const
{
    return 3.14 * r * r;
}

void circle::getInformation() const
{
    std::cout << "Name of figure: Circle.\n";
    std::cout << "Radius is " << r << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}


