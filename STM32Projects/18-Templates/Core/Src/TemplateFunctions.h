#pragma once

#include <iostream>

namespace functions
{

template<typename T>
// template<class T> // same in most of cases
T sum(T a, T b, T c)
{
    std::cout << "Calling " << __PRETTY_FUNCTION__ << std::endl;
    return a + b + c;
}

// specialization
template<>
bool sum<bool>(bool a, bool b, bool c)
{
    std::cout << "Calling specialization" << __PRETTY_FUNCTION__ << std::endl;
    return a || b || c;
}

} // namespace functions