#pragma once

#include <memory>

#include "HardwareBlitter.h"

class BlitterDeleter
{
public:
    explicit BlitterDeleter(HardwareBlitter& blitter);
    void operator()(int* address);

private:
    HardwareBlitter& blitter;
};

class BlitterAllocator
{

public:
    BlitterAllocator() = default;

    using ImagePtr = std::unique_ptr<int, BlitterDeleter>;

    ImagePtr allocate(int width, int height);

private:
    HardwareBlitter hardwareBlitter;
};
