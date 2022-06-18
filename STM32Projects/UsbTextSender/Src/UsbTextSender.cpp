#include "UsbTextSender.h"

#include <stm32h743xx.h>

namespace usbTextSender
{

namespace
{

constexpr unsigned systemFrequency = 16'000'000;
constexpr unsigned defaultBaudrate = 115'200;

constexpr unsigned enableGPIO_B = (1 << 1);        // GPIOBEN
constexpr unsigned enableGPIO_D = (1 << 3);        // GPIOBEN

constexpr unsigned uart3Enable = 1 << 18;          // UE

constexpr unsigned enableTransmiting = (1U << 3);  // CR1_TE
constexpr unsigned usartControlEnable = (1U << 0); // CR1_UE
constexpr unsigned usartEnableFifoMode = (1U << 29); // CR1_FIFOEN

enum class StopBits
{
	ONE,
	TWO,
	HALF,
	ONE_AND_HALF,
};

USART_TypeDef* const USART3_ADDRESS = USART3;  // taken from stm32h743xx.h

uint16_t computeUartSpeed(uint32_t peripherialClock, uint32_t baudrate)
{
//	auto usartDiv = peripherialClock / (peripherialClock);
//	constexpr uint32_t over = 0;
//	return peripherialClock / (8 * (2 - over) usartDiv );
//	return (peripherialClock + baudrate / 2U) / baudrate;
	auto usartDiv = peripherialClock / baudrate;
	return usartDiv;
}

void setBaudrate(USART_TypeDef* usart, uint32_t peripherialClock, uint32_t baudrate)
{
	usart->BRR = computeUartSpeed(peripherialClock, baudrate);
}

bool isWriteRegisterEmpty(USART_TypeDef* usart)
{
	constexpr unsigned isDataRegisterEmptyBit = (1 << 7); // TXE
	return static_cast<bool>(usart->ISR & isDataRegisterEmptyBit);
}

void setStopBit(USART_TypeDef* usart, StopBits mode)
{
	constexpr auto firstBit = (1 << 12);
	constexpr auto secondBit = (1 << 13);
	switch (mode)
	{
	case StopBits::ONE:
		usart->CR2 &= ~firstBit;
		usart->CR2 &= ~secondBit;
		break;
	case StopBits::TWO:
		usart->CR2 &= ~firstBit;
		usart->CR2 |= secondBit;
		break;
	case StopBits::HALF:
		usart->CR2 |= firstBit;
		usart->CR2 &= ~secondBit;
		break;
	case StopBits::ONE_AND_HALF:
		usart->CR2 |= firstBit;
		usart->CR2 |= secondBit;
		break;
	}
}

void writeCharacterToUsart(int mark)
{
	while (!isWriteRegisterEmpty(USART3_ADDRESS));

	USART3_ADDRESS->TDR = mark & 0xFF;
}

} // namespace

bool initUsart3Sending(uint32_t baudrate)
{
	RCC->AHB4ENR |= enableGPIO_B;
	RCC->AHB4ENR |= enableGPIO_D;

	// Alternate mode 0b10
	GPIOB->MODER &= ~(1U << 6);
	GPIOB->MODER |= (1U << 7);

	// AFRL: AFR[0]
	// AFRH: AFR[1]
	// AF7 mode: 0111
	GPIOB->AFR[0] |= (1U << 12);
	GPIOB->AFR[0] |= (1U << 13);
	GPIOB->AFR[0] |= (1U << 14);
	GPIOB->AFR[0] &= ~(1U << 15);

	RCC->APB1LENR |= uart3Enable;

	// set the M bits
	USART3_ADDRESS->CR1 = 0;

	USART3_ADDRESS->CR1 &= ~usartEnableFifoMode;

	setBaudrate(USART3_ADDRESS, systemFrequency, baudrate);
	setStopBit(USART3_ADDRESS, StopBits::ONE);

	USART3_ADDRESS->CR1 |= usartControlEnable;

	USART3_ADDRESS->CR1 |= enableTransmiting;

	return true;
}

bool initUsart3Sending()
{
	return initUsart3Sending(defaultBaudrate);
}

bool sendText(const std::string& text)
{
	for (const auto character : text)
	{
		writeCharacterToUsart(static_cast<int>(character));
	}

	return true;
}

bool sendCharacter(char character)
{
	//return writeCharacterToUsart(static_cast<int>(character));
	writeCharacterToUsart(static_cast<int>('Y'));

	return true;
}

} // namespace usbTextSender
