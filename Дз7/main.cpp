#include <iostream>
#include "Figures.h"

int main()
{
    std::vector<Figure*> figurePtrs(1);

    figurePtrs[0] = new Square(10);
    std::cout << '\n';
    figurePtrs[0]->getInformation();
    delete figurePtrs[0];
    std::cout << "\nPerimeter: ";
    std::cout << "\nSquare: ";
    std::cout << "\nInformation: ";

    figurePtrs[0] = new Circle(10);
    std::cout << '\n';
    figurePtrs[0]->getInformation();
    delete figurePtrs[0];
    std::cout << "\nPerimeter: ";
    std::cout << "\nSquare: ";
    std::cout << "\nInformation: ";

    figurePtrs[0] = new Triangle(3, 4, 5);
    std::cout << '\n';
    figurePtrs[0]->getInformation();
    delete figurePtrs[0];
    std::cout << "\nPerimeter: ";
    std::cout << "\nSquare: ";
    std::cout << "\nInformation: ";

    figurePtrs[0] = new Rectangle(4, 5);
    std::cout << '\n';
    figurePtrs[0]->getInformation();
    delete figurePtrs[0];
    std::cout << "\nPerimeter: ";
    std::cout << "\nSquare: ";
    std::cout << "\nInformation: ";

    figurePtrs[0] = new Ellipse(4, 7);
    std::cout << '\n';
    figurePtrs[0]->getInformation();
    delete figurePtrs[0];
    std::cout << "\nPerimeter: ";
    std::cout << "\nSquare: ";
    std::cout << "\nInformation: ";

    return 0;
}
