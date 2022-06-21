#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

template<typename T, int Capacity = 10>
class Array
{
public:
    Array();

    explicit Array(const T& initialValue);
    T at(size_t index) const;
    void set(size_t index, const T& value);

    constexpr static int size = Capacity;

private:
    T data[Capacity];
};

// specialization
template<int Capacity>
class Array<bool, Capacity>
{
public:
    Array();
    bool at(size_t index) const;
    void set(size_t index, bool value);

    const static int size = Capacity;

private:
    constexpr static size_t arraySize = Capacity / (sizeof(unsigned) * 8) + 1;
    unsigned data[arraySize];
};

template<typename T, int count>
Array<T, count>::Array()
  : Array(0)
{
}

template<typename T, int count>
Array<T, count>::Array(const T& initialValue)
{
    std::cout << "Constructing template class:" << __PRETTY_FUNCTION__ << std::endl;
    for (int i = 0; i < count; ++i) {
        data[i] = initialValue;
    }
}

template<typename T, int count>
T Array<T, count>::at(size_t index) const
{
    return data[index];
}

template<typename T, int count>
void Array<T, count>::set(size_t index, const T& value)
{
    data[index] = value;
}

template<int count>
Array<bool, count>::Array()
{
    std::cout << "Constructing specialization class:" << __PRETTY_FUNCTION__ << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        data[i] = 0;
    }
}

template<int count>
bool Array<bool, count>::at(size_t index) const
{
    return false;
}

template<int count>
void Array<bool, count>::set(size_t index, bool value)
{
}
