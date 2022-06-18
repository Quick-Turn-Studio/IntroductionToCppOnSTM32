#include <init.h>
#include <messageSender.h>

#include <sstream>
#include <memory>

#include "BlitterAllocator.h"

class Class
{
public:
    Class() = default;
    Class(int a, float b, bool c)
    {
    }
};


int main()
{
	init();

	messageSender::send("Running 14-UniquePtr project");

	std::unique_ptr<int> ptr1;
	std::unique_ptr<int> ptr2{new int{4}};

	ptr1 = std::move(ptr2);

	if (ptr1) {
		messageSender::send("I has value");
	}
	if (!ptr2) {
		messageSender::send("Now I am null");
	}

	auto classPtr01 = std::unique_ptr<Class>(new Class(10, 9.99F, false));
	auto classPtr02 = std::make_unique<Class>(10, 9.99F, false);

	auto size = 15;
	auto dynamicSizeArray = std::make_unique<Class[]>(size);

	auto blitter = BlitterAllocator();
	auto image = blitter.allocate(640, 480);

	return 0;
}
