#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Array.h"
#include "TemplateFunctions.h"

int main()
{
	init();

	messageSender::send("Running Task04-TemplatedCapacityContainer project");

	std::stringstream stream;

	stream << "Integers sum: " << functions::sum(1, 3, 4) << std::endl;
	// stream << "Floats sum: " << functions::sum(1.2F, 3.0F, 4.5F) << std::endl;
	stream << "Bool sum: " << functions::sum(true, false, true) << std::endl;

	//        stream << "Mixed sum: " << functions::sum(1, 3.0F, 4.5) << std::endl;
	stream << "Mixed sum: " << functions::sum<float>(1, 3.0F, 4.5) << std::endl;

	Array<int, 10> intsArray;

	intsArray.set(0, 1000);
	intsArray.set(1, 10000);

	stream << "Ints element: " << intsArray.at(0) << std::endl;

	Array<bool, 7> boolsArray;
	boolsArray.set(0, true);
	boolsArray.set(1, false);
	stream << "Bools element: " << boolsArray.at(0) << std::endl;

	// Array deductedTypeArray(100.0F); // from C++17 we have decuction types
	// stream << "Deduced element: " << deductedTypeArray.at(0) << std::endl;

	messageSender::send(stream.str());

	return 0;
}
