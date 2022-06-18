#include <init.h>
#include <messageSender.h>

#include <sstream>

int main()
{
	init();

	messageSender::send("Running Task01-CustomStream project");

	return 0;
}
