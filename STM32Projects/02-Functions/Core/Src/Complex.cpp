#include "Complex.h"

#include <sstream>

Complex::Complex()
        : real(0)
        , imaginary(0)
{
}

Complex::Complex(int real, int imaginary)
        : real(real)
        , imaginary(imaginary)
{
}

void Complex::setValue(int real, int imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

int Complex::getReal() const
{
    return real;
}

int Complex::getImaginary() const
{
    return imaginary;
}

std::string Complex::toString() const
{
    std::stringstream stream;
    stream << real;
    if (imaginary != 0) {
        stream << (imaginary > 0 ? " + " : " - ") << imaginary << "i";
    }
    return stream.str();
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
}

std::ostream& operator<<(std::ostream& stream, const Complex& complex)
{
    return stream << complex.toString();
}

Complex Complex::operator+(const Complex& complex)
{
    Complex sum;
    sum.real = real + complex.real;
    sum.imaginary = imaginary + complex.imaginary;

    return sum;
}