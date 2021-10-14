#include <iostream>
#include "SmartPtr.h"

int main()
{
    double tmp, tmp1;
    std::cout << "Double value: " << std::endl;
    std::cin >> tmp;
    double* ptr = &tmp;

    SmartPtr ptr1(tmp);
    SmartPtr ptr2(ptr);

    std::cout << "ptr  " << ptr << std::endl;
    std::cout << "ptr1 " << ptr1 << std::endl;
    std::cout << "ptr2 " << ptr2 << std::endl;
    std::cout << "tmp " << tmp << std::endl;
    std::cout << "Value1 " << *ptr1 << std::endl;
    std::cout << "Value2 " << *ptr2 << std::endl;

    return 0;
}
