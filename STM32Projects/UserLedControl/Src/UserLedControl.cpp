#include "UserLedControl.h"

#include <stm32h743xx.h>

namespace
{

// user LD1:
// PB0 (SB39 ON and SB47 OFF) or PA5 (SB47 ON and SB39 OFF)

constexpr unsigned enableGPIO_B = 1U << 1;
constexpr unsigned LED_PIN = 1U << 0;
}

namespace userLed1
{

bool enable()
{
	RCC->AHB4ENR |= enableGPIO_B;
	GPIOB->MODER |= (1U<<0);
	GPIOB->MODER &= ~(1U<<1);
	return true;
}

bool turnOn()
{
	GPIOB->ODR |= LED_PIN;
	return true;
}

bool turnOff()
{
	GPIOB->ODR &= ~LED_PIN;
	return true;
}

bool setState(bool turnState)
{
	return turnState ? turnOn() : turnOff();
}

bool toggle()
{
	GPIOB->ODR ^= LED_PIN;
	return true;
}

}
