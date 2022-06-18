#ifndef USBTEXTSENDER_H
#define USBTEXTSENDER_H

#include <cstdint>
#include <string>

namespace usbTextSender
{

[[nodiscard]] bool initUsart3Sending(uint32_t boudrate);
[[nodiscard]] bool initUsart3Sending();

bool sendText(const std::string& text);
bool sendCharacter(char character);

} // namespace usbTextSender

#endif /* USBTEXTSENDER_H */
