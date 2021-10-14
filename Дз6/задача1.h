

#ifndef SMART_PTR
#define SMART_PTR

#include "SmartPtr.h"

SmartPtr::SmartPtr(double obj)
{
    m_ptr = new double{ obj };
    return;
}

double& operator* (SmartPtr ptr)
{
    return *ptr.m_ptr;
}

std::ostream& operator<<(std::ostream& out, const SmartPtr& ptr)
{
    out << ptr.m_ptr;
    return out;
}

#endif //SMART_PTR
