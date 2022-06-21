#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Class.h"

Class globalAllocated("Global");

template<typename T>
bool compareAddresses(const T* ptr1, const T* ptr2)
{
    if (ptr1 == ptr2) {
    	messageSender::send("Objects are in same address\n");
        return true;
    }
    else {
    	messageSender::send("Objects are in different addresses\n");
        return false;
    }
}
int main()
{
	init();

	messageSender::send("Running 08d-ConstMemory project");

	std::stringstream stream;

    const char* constString1 = "Text";
    const char* constString2 = "Text";
    std::string string3 = "Text";

    stream << "Comparing constString1 and constString2:\n";
    compareAddresses(constString1, constString2);

    stream << "Comparing constString1 and string:\n";
    compareAddresses(constString1, string3.c_str());

    const Class cs1;
    const Class cs2;

    stream << "Comparing cs1 and cs2:\n";
    compareAddresses(&cs1, &cs2);

	messageSender::send(stream.str());

	return 0;
}
