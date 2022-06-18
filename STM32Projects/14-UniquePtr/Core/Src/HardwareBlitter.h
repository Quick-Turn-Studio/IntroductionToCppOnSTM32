#pragma once

class HardwareBlitter
{
public:
    int* allocateImage(int width, int height);
    void deallocate(int* address);
};
