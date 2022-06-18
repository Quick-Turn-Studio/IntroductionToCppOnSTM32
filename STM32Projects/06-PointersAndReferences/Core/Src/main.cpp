#include <init.h>
#include <messageSender.h>

#include <sstream>

int main()
{
	init();

	messageSender::send("Running 05-ClassesAndStructures project");

	std::stringstream stream;



	messageSender::send(stream.str());
}
