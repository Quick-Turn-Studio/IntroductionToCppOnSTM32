#pragma once

#include <string>

class Person
{
public:
    ~Person();
    Person(std::string name);
    Person(std::string name, int salary);

    void setSalary(int salary);
    int getSalary();
    std::string getName();

private:
    int salary = 0;
    std::string name;
};
