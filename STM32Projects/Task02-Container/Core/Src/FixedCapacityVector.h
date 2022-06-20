#ifndef SRC_FIXEDCAPACITYVECTOR_H_
#define SRC_FIXEDCAPACITYVECTOR_H_

#include <cstdint>

class FixedCapacityVector
{
public:
	explicit FixedCapacityVector(uint32_t capacity);

	int getCapacity() const;
	int getSize() const;

	bool add(int value);
	bool remove(int index);

	int& operator[](uint32_t index);
	const int& operator[](uint32_t index) const;

	bool empty() const;

private:
	int* data = nullptr;
	int size = 0;
	int capacity = 0;
};

#endif /* SRC_FIXEDCAPACITYVECTOR_H_ */
