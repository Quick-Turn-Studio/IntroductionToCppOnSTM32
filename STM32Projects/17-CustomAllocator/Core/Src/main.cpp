#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Allocator.h"

struct A
{
    A(int a, float b)
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
    ~A()
    {
        messageSender::send(__PRETTY_FUNCTION__);
    }
};


int main()
{
	init();

	messageSender::send("Running 17-CustomAllocator project");

    Allocator<A, 3> allocator;

    messageSender::send("Alloc A");
    auto a = allocator.allocate(4, 4.0f);

    messageSender::send("Alloc B");
    auto b = allocator.allocate(2, 2.0f);

    a.reset();

    messageSender::send("Alloc D");
    auto d = allocator.allocate(0, 0);

    messageSender::send("Alloc C");
    auto c = allocator.allocate(1, 1.0f);

    messageSender::send("Finished");

	return 0;
}
