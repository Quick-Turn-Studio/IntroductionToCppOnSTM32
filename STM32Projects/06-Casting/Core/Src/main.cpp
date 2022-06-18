#include <init.h>
#include <messageSender.h>

#include <sstream>

struct A
{
    // A(int initialValue)
    explicit A(int initialValue)
      : number(initialValue)
    {
    }
    int number = 10;

    explicit operator bool() const
    {
        return number != 0;
    }
};

int main()
{
	init();

	messageSender::send("Running 06-Casting project");

	//A object = 10;
    A object = static_cast<A>(10);
    // double number = object;
    double number = static_cast<bool>(object);

    return 0;
}
