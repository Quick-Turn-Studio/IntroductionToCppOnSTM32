#include "Class.h"

#include <messageSender.h>

#include <sstream>

Class::~Class()
{
	std::stringstream stream;
	stream << "Deleting: " << name << '\n';
	messageSender::send(stream.str());
}

Class::Class() : Class("Default constructed")
{

}

Class::Class(const std::string& name)
        : name(name)
{
	std::stringstream stream;
	stream << "Constructing: " << name << '\n';
	messageSender::send(stream.str());
}
