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
    void setValue(int value);
    int getValue() const;

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

	messageSender::send("Running 06b-References project");

	std::stringstream stream;

	A value;
	A& ref = value;

	A secondValue;
	secondValue.number = 20;
	stream << "value: " << value << '\n';
	stream << "secondValue: " << secondValue << '\n';

	ref = secondValue;

	stream << "value: " << value << '\n';
	stream << "secondValue: " << secondValue << '\n';

	messageSender::send(stream.str());

	return 0;
}
