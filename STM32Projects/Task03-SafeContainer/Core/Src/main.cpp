#include <init.h>
#include <messageSender.h>

#include <sstream>

int main()
{
	init();

	messageSender::send("Running Task03-Safe-Container project");


	return 0;
}
