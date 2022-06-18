#include <init.h>
#include <messageSender.h>

#include <sstream>

struct A
{
    int number = 0;
};

class X
{
public:
    void setValue(int value)
    {
    	number = value;
    }
    int getValue() const
    {
    	return number;
    }

private:
    int number = 0;
};

std::ostream& operator << (std::ostream& stream, A a)
{
    return stream << a.number;
}

void doubleValue(A* pointer)
{
    if (nullptr == pointer) {
        return;
    }
    pointer->number = 2 * pointer->number;
}

int main()
{
	init();

	messageSender::send("Running 06a-Pointers project");

	std::stringstream stream;

	A value;
	stream << "After construction: " << value << '\n';

	value.number = 10;
	stream << "After change: " << value << '\n';

	A* pointerToFirst = &value;
	pointerToFirst->number = 20;
	stream << "After using pointer: " << value << '\n';

	A* anotherPtr = pointerToFirst;
	anotherPtr->number = 50;
	stream << "Again: " << value << '\n';

	A* ptr = nullptr;
	stream << "Address: " << ptr << '\n';
	ptr = &value;
	stream << "Address: " << ptr << '\n';

	stream << "Value from pointer: " << *ptr << '\n';

	A anotherValue = *ptr;

	stream << "value: " << value << '\n';
	stream << "anotherValue: " << anotherValue << '\n';

	anotherValue.number = 100;

	stream << "value: " << value << '\n';
	stream << "anotherValue: " << anotherValue << '\n';

	// doubleValue(ptr);
	stream << "doubled value: " << value << '\n';

	ptr = nullptr;
	// doubleValue(ptr);

	// const A constValue;
	// const A* constPtr = nullptr;
	// constPtr = &constValue;

	X nonConstValue;
	nonConstValue.setValue(10);
	stream << "From value: " << nonConstValue.getValue() << '\n';

	const X* constPtr = &nonConstValue;
    //  constPtr->setValue(10); // illegal, setValue is not const function
	stream << "From pointer " << nonConstValue.getValue() << '\n';

	messageSender::send(stream.str());

	return 0;
}
