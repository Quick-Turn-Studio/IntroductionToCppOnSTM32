#pragma once

#include <string>

class Class
{
public:
    Class();
    Class(const std::string& name);
    ~Class();

    static int getCreationTimes();

private:
    std::string name;

    static int creationsCount;
};
