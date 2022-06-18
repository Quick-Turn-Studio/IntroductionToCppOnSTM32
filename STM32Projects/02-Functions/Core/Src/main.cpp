#include <init.h>
#include <messageSender.h>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "FunctionExamples.h"

int main()
{
	init();

	messageSender::send("Running 02-Functions project");

	foo(20);

	std::ostringstream stream;

	sum(10, 20);
	sum(100, 20, 30);

	sum(100.0F, 20.0F);
	sum(100.0F, 20.0F, 20.0F);

}
