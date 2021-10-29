#include "Figures.h"
#include <cmath>

double Ellipse::getPerimeter() const
{
    if (a - b != 0){
        return (3.14 * (a + b) * (1 + (3 * (pow((a - b) / (a + b), 2)) / (10 + pow((4 - 3 * pow((a - b) / (a + b), 2)), 0.5)))));
    }
    else{
        return 0;
    }

}
double Ellipse::getSquare() const
{
    return a * b * 3.14;
}

void Ellipse::getInformation() const
{
    std::cout << "Name of figure: ellipse.\n";
    std::cout << "The large semi - axis is " << a << ".\n";
    std::cout << "The small semi -  axis is " << b << ".\n";
    std::cout << "Perimeter is " << getPerimeter() << ".\n";
    std::cout << "Square is " << getSquare() << ".\n\n";
}
