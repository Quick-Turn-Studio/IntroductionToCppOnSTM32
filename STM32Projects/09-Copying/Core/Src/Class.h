#pragma once

class Class
{
public:
    Class();
    ~Class();

    Class(const Class& object);
    Class& operator=(const Class& object);
};
