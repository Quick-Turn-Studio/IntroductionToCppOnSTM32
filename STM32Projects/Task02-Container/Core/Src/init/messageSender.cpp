#include <messageSender.h>

#include "init.h"

namespace messageSender
{

void send(const std::string& message)
{
	sendText(reinterpret_cast<const uint8_t*>(message.c_str()), message.size() + 1);
}

}
