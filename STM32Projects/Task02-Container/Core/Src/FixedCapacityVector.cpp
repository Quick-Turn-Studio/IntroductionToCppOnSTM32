#include "FixedCapacityVector.h"

FixedCapacityVector::FixedCapacityVector(uint32_t capacity)
 : data(new int[capacity]), size(0), capacity(capacity)
{

}

int FixedCapacityVector::getCapacity() const
{
	return capacity;
}

int FixedCapacityVector::getSize() const
{
	return size;
}

bool FixedCapacityVector::add(int value)
{
	if (size == capacity) {
		return false;
	}
	data[size++] = value;
	return true;
}

bool FixedCapacityVector::remove(int index)
{
	if (0 == size) {
		return false;
	}
	for (auto i = index; i < size - 1; ++i) {
		data[i] = data[i + 1];
	}
	--size;

	return true;
}

int& FixedCapacityVector::operator[](uint32_t index)
{
	return data[index];
}

const int& FixedCapacityVector::operator[](uint32_t index) const
{
	return data[index];
}

bool FixedCapacityVector::empty() const
{
	return 0 == size;
}
