#include "Class.h"

#include <iostream>

int Class::creationsCount = 0;

Class::~Class()
{
    std::cout << "Deleting: " << name << '\n';
}

Class::Class()
        : name("default constructed")
{
    std::cout << "Default constructed\n";
    ++creationsCount;
}

Class::Class(const std::string& name)
        : name(name)
{
    std::cout << "Constructing: " << name << '\n';
    ++creationsCount;
}

int Class::getCreationTimes()
{
    return creationsCount;
}
