#pragma once

#include <string>

class Class
{
public:
	Class();
    Class(const std::string& name);
    ~Class();

private:
    std::string name;
};
