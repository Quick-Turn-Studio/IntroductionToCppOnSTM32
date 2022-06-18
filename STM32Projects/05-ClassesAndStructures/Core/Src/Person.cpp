#include "Person.h"

#include <iostream>

Person::~Person()
{
    std::cout << name << " is destroyed" << std::endl;
}

Person::Person(std::string name)
        : Person(name, 0)
{
}

Person::Person(std::string name, int salary)
        : name(name)
        , salary(salary)
{
}

std::string Person::getName()
{
    return name;
}

void Person::setSalary(int salary)
{
    this->salary = salary;
}

int Person::getSalary()
{
    return salary;
}
