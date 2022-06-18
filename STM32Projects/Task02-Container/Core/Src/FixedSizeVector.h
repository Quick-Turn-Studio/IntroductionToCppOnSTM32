#ifndef SRC_FIXEDSIZEVECTOR_H_
#define SRC_FIXEDSIZEVECTOR_H_

#include <cstdint>

class FixedSizeVector
{
public:
	explicit FixedSizeVector(uint32_t size);

	int capacity() const;
	int size() const;

	bool add(int value);
	bool remove(int index);

	int& operator[](uint32_t index);
	const int& operator[](uint32_t index) const;

	bool empty() const;
};

#endif /* SRC_FIXEDSIZEVECTOR_H_ */
