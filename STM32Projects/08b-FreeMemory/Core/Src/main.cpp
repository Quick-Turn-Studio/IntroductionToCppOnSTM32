#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Class.h"

int main()
{
	init();

	messageSender::send("Running 08b-FreeMemory project");

	Class* fm1 = new Class("FM1");

	Class* fm2 = new Class("FM2");

	Class* fm3A = nullptr;
	{
		Class* fm3 = new Class("FM3");
		fm3A = fm3;
	}
	Class* fm4 = new Class("FM4");

	Class* fm2A = fm2;

	delete fm2;
	delete fm1;
	// delete fm3; // fm3 do not exist here
	delete fm3A;

	// ================================================

	Class* array = new Class[3]; // new[] operator
	delete[] array;

	Class* nothrowAllocated = new (std::nothrow) Class("FM5");
	delete nothrowAllocated;

	return 0;
}
