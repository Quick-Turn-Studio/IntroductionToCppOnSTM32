#include "BlitterAllocator.h"

#include <iostream>

BlitterDeleter::BlitterDeleter(HardwareBlitter& blitter)
  : blitter(blitter)
{
}

void BlitterDeleter::operator()(int* address)
{
    blitter.deallocate(address);
}

BlitterAllocator::ImagePtr BlitterAllocator::allocate(int width, int height)
{
    auto deleter = BlitterDeleter(hardwareBlitter);
    auto blitterMemory = hardwareBlitter.allocateImage(width, height);

    return ImagePtr(blitterMemory, deleter);
}