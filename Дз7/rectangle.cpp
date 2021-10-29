#include "Figures.h"

double Rectangle::getPerimeter() const
{
    return 2 * (a + b);
}

double Rectangle::getSquare() const
{
    return a * b;
}

void Rectangle::getInformation() const
{
    std::cout << "Name of figure: Rectangle.\n";
    std::cout << "Length is " << a << ".\n";
    std::cout << "Width is " << b << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}
