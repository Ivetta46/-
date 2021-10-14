#include <iostream>

#ifndef SMART_PTR
#define SMART_PTR


class SmartPtr {
private:
    double* m_ptr;
public:
    SmartPtr() = default;
    SmartPtr(double* ptr) : m_ptr(ptr) {}
    SmartPtr(double);
    SmartPtr(const SmartPtr& another) : m_ptr(another.m_ptr) {}
    ~SmartPtr();

    friend double& operator* (SmartPtr);
    friend std::ostream& operator<<(std::ostream&, const SmartPtr&);

};


#endif //SMART_PTR
