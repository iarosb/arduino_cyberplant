#ifndef Led_H
#define Led_H
#include "Arduino.h"

void ledInit_input(int pin);
void ledInit_output(int pin);

void ledOn(int pin);
void ledOff(int pin);

bool isLedOn(int pin);

#endif