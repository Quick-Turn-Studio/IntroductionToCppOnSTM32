#include <init.h>
#include <messageSender.h>

#include <sstream>

#include "Class.h"

void passParameterByCopy(Class arg)
{
}

void passParameterByRef(const Class& arg)
{
}

class Collection
{
public:
    Collection(const Class& element)
      : element(element)
    {
    }

private:
    Class element;
};

int main()
{
	init();

	messageSender::send("Running 09-Copying project");

	Class obj;

	passParameterByCopy(obj);
	passParameterByRef(obj);

	Collection collection(obj);

	Class anotherObject;

	obj = anotherObject;

	return 0;
}
