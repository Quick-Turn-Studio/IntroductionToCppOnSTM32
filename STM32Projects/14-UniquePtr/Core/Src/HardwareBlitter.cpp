#include "HardwareBlitter.h"

#include <iostream>

int* HardwareBlitter::allocateImage(int width, int height)
{
    std::cout << "Allocating image with size: " << width << "x" << height << std::endl;
    return new int[width * height];
}

void HardwareBlitter::deallocate(int* address)
{
    std::cout << "Deallocating address" << std::endl;
    delete[] address;
}
