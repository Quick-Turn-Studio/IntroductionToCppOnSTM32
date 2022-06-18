#ifndef USERLEDCONTROL_H_
#define USERLEDCONTROL_H_


namespace userLed1
{

[[nodiscard]] bool enable();

bool turnOn();
bool turnOff();
bool setState(bool turnState);
bool toggle();

}


#endif /* USERLEDCONTROL_H_ */
