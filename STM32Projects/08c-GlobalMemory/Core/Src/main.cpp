#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Class.h"

Class globalAllocated("Global");

void printCreations()
{
	std::stringstream stream;
	stream << "Current creation count is " << Class::getCreationTimes() << '\n';
	messageSender::send(stream.str());
}

void staticInFunction()
{
    static Class globalAllocated("Global in function");
    std::stringstream stream;
    stream << __PRETTY_FUNCTION__  << '\n';
    messageSender::send(stream.str());
}

int main()
{
	init();

	messageSender::send("Running 08c-GlobalMemory project");

    printCreations();

    Class c1("Stack");

    printCreations();

    staticInFunction();
    staticInFunction();
    staticInFunction();

    printCreations();


	return 0;
}
