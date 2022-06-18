#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Class.h"

int main()
{
	init();

	messageSender::send("Running 08aStack project");

    Class s1("S1");
    Class s2("S2");

    {
        Class s3("S3");
    }
    Class s4("S4");


	return 0;
}
