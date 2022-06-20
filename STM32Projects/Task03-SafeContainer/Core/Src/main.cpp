#include <init.h>
#include <messageSender.h>

#include <sstream>

int main()
{
	init();

	messageSender::send("Running Task02-Container project");


	return 0;
}
