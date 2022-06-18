#pragma once

#include <array>
#include <memory>

template<typename T, int capacity>
class Allocator final
{
public:
    struct Deleter
    {
        void operator()(T* ptr)
        {
            allocator->deallocate(ptr);
        }
        Allocator* allocator = nullptr;
    };

    using Pointer = std::unique_ptr<T, Deleter>;

public:
    Allocator();
    ~Allocator();

    template<typename... Args>
    Pointer allocate(Args... args);

private:
    void deallocate(T* ptr);
    int getFirstFreeMemoryPosition();

private:
    std::array<bool, capacity> allocationFlags;
    void* memory = nullptr;
};

template<typename T, int capacity>
Allocator<T, capacity>::~Allocator()
{
    auto ptr = static_cast<T*>(memory);
    for (auto i = capacity; i >= 0; --i, ++ptr) {
        if (!allocationFlags[i]) {
            continue;
        }
        deallocate(ptr);
    }
    operator delete(memory);
}

template<typename T, int capacity>
Allocator<T, capacity>::Allocator()
        : memory(operator new(sizeof(T) * capacity))
{
    for (auto i = 0; i < capacity; ++i) {
        allocationFlags[i] = false;
    }
}

template<typename T, int capacity>
template<typename... Args>
typename Allocator<T, capacity>::Pointer Allocator<T, capacity>::allocate(Args... args)
{
    const auto freeMemoryIndex = getFirstFreeMemoryPosition();
    if (capacity == freeMemoryIndex) {
    	// handle error, eg:
        // throw std::bad_alloc();
    	// or
    	// return nullptr
    	return {};
    }

    T* freeMemory = static_cast<T*>(memory);
    freeMemory += freeMemoryIndex;

    allocationFlags[freeMemoryIndex] = true;

    auto pointer = Pointer(new (freeMemory) T(std::forward<Args>(args)...));
    pointer.get_deleter().allocator = this;

    return pointer;
}

template<typename T, int capacity>
int Allocator<T, capacity>::getFirstFreeMemoryPosition()
{
    for (auto i = 0; i < capacity; ++i) {
        if (allocationFlags[i]) {
            continue;
        }
        return i;
    }
    return capacity;
}

template<typename T, int capacity>
void Allocator<T, capacity>::deallocate(T* ptr)
{
    T* firstElementPtr = static_cast<T*>(memory);
    const auto index = ptr - firstElementPtr;

    if (index < 0 || index >= capacity) {
        return;
    }
    if (!allocationFlags[index]) {
        return;
    }

    ptr->~T();
    allocationFlags[index] = false;
}
