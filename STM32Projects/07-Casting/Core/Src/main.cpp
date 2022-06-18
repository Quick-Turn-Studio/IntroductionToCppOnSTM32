#include <init.h>
#include <messageSender.h>

#include <sstream>

struct A
{
    A(const char* text)
    {
    }

    // A(int initialValue)
    explicit A(int initialValue)
      : number(initialValue)
    {
    }
    int number = 10;

    operator bool() const
    {
        return number != 0;
    }
};

void printString(std::string text)
{
	messageSender::send("Printing text: ");
}

void print(A a)
{
	messageSender::send("Printing a...");;
}

int main()
{
	init();

	messageSender::send("Running 07-Casting project");

	A object = static_cast<A>(10);

	if (object) {
		messageSender::send("Value is not zero");
	}
	else {
		messageSender::send("We have zero inside");
	}

	const char* txt = "My text";

	printString(txt);

	print(A(10));


	return 0;
}
