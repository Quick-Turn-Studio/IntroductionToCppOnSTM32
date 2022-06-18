#include <init.h>
#include <messageSender.h>

#include <sstream>

int main()
{
	init();

	while (1)
	{
		messageSender::send("Hello World!");

		std::stringstream stream;

		stream << "You can use stream ";
		stream << "if you want to display numbers, eg" << std::endl;
		int integer = 100;
		stream << "integer" << integer << std::endl;

		uint32_t unsignedInteger = 10;
		stream << "or uint32_t" << unsignedInteger << std::endl;

//		float floatingNumber = 10.2F;
//		stream << "But care about floats... " << floatingNumber << std::endl;

		messageSender::send(stream.str());

		// sleep for 1 second
		delay(1000);
	}
}
