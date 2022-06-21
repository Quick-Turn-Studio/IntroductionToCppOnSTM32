#ifndef SRC_TEMPLATEDCAPACITYSIZEVECTOR_H_
#define SRC_TEMPLATEDCAPACITYSIZEVECTOR_H_

#include <cstdint>

template<typename T, int capacity>
class TemplatedFixedSizeVector {
public:
	explicit TemplatedFixedSizeVector(uint32_t size);

	int capacity() const;
	int size() const;

	bool add(T value);
	bool remove(int index);

	T& operator[](uint32_t index);
	const T& operator[](uint32_t index) const;

	bool empty() const;
};

#endif /* SRC_TEMPLATEDCAPACITYSIZEVECTOR_H_ */
