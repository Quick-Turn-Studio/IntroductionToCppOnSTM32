#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Person.h"

int main()
{
	init();

	messageSender::send("Running 05-ClassesAndStructures project");

	std::stringstream stream;

	// Person john;
	Person john("John");
	john.setSalary(1200);

	Person michael("Michael", 1400);
	 stream << john.getSalary() << '\n';

	// stream << john.getName() << "earns " << john.getSalary() << '\n';
	// stream << michael.getName() << "earns " << michael.getSalary() << '\n';

	// john.annualSalary = 1000;   // will not compile, annualSalary is private
	// stream << john.getMonthCount();   // same

	messageSender::send(stream.str());
}
