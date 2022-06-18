#pragma once

#include <string>
#include <ostream>

class Complex
{
public:
    Complex();
    Complex(int real, int imaginary);

    void setValue(int real, int imaginary);
    int getReal() const;
    int getImaginary() const;

    Complex operator + (const Complex& complex);

    std::string toString() const;

private:
    int real = 0;
    int imaginary = 0;
};

Complex operator - (const Complex& c1, const Complex& c2);
std::ostream& operator << (std::ostream& stream, const Complex& complex);
