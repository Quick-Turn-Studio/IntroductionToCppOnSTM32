#include <init.h>
#include <messageSender.h>

#include <sstream>

// struct alignas(8) A
// struct alignas(long int) A
struct A
{
    int a;
    int b;
    char c;
    char d;
};

// struct alignas(8) B
// struct alignas(long int) B
struct B
{
    char c;
    int a;
    char d;
    int b;
};

struct AB
{
    A x;
    B z;
    int a;
};

struct XY
{
    int a;
    B z;
    A x;
};


int main()
{
	init();

	messageSender::send("Running 05a-ClassesAndStructures project");

	std::stringstream stream;

	stream << "size of A is: " << sizeof(A) << '\n';
	stream << "size of B is: " << sizeof(B) << '\n';

	stream << "align of char is: " << alignof(char) << '\n';
	stream << "align of int is: " << alignof(int) << '\n';
	stream << "align of pointer is: " << alignof(int*) << '\n';
	stream << "align of A is: " << alignof(A) << '\n';
	stream << "align of B is: " << alignof(B) << '\n';

	stream << "size of AB is: " << sizeof(AB) << '\n';
	stream << "size of XY is: " << sizeof(XY) << '\n';

	messageSender::send(stream.str());
}
