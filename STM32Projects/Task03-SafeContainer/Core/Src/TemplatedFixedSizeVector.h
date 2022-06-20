#ifndef SRC_TEMPLATEDFIXEDSIZEVECTOR_H_
#define SRC_TEMPLATEDFIXEDSIZEVECTOR_H_

#include <cstdint>

template<typename T>
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

#endif /* SRC_TEMPLATEDFIXEDSIZEVECTOR_H_ */
