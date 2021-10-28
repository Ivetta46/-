#include "Figures.h"

double Square::getPerimeter() const
{
    return a * 4;
}

double Square::getSquare() const
{
    return a * a;
}

void Square::getInformation() const
{
    std::cout << "Name of figure: Square.\n";
    std::cout << "Side is " << a << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}
