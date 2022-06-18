#include "Class.h"

#include <messageSender.h>

Class::~Class()
{
    messageSender::send(__PRETTY_FUNCTION__);
}

Class::Class()
{
    messageSender::send(__PRETTY_FUNCTION__);
}

Class::Class(const Class& object)
{
    messageSender::send(__PRETTY_FUNCTION__);
}

Class& Class::operator=(const Class& object)
{
	messageSender::send(__PRETTY_FUNCTION__);
    return *this;
}
