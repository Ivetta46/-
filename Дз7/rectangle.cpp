#include "Figures.h"

double rectangle::getPerimeter() const
{
    return 2 * (a + b);
}

double rectangle::getSquare() const
{
    return a * b;
}

void rectangle::getInformation() const
{
    std::cout << "Name of figure: Rectangle.\n";
    std::cout << "Length is " << a << ".\n";
    std::cout << "Width is " << b << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}
