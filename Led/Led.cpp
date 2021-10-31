#include "Led.h"

void ledInit_input(int pin)
{
  pinMode(pin, INPUT);
}

void ledInit_output(int pin)
{
  pinMode(pin, OUTPUT);
}

void ledOn(int pin)
{
  digitalWrite(pin, HIGH);
}

void ledOff(int pin)
{
  digitalWrite(pin, LOW);
}

bool isLedOn(int pin)
{
  if(digitalRead(pin) == HIGH)
  {
    Serial.print("Led is on");
    Serial.println();
    return true;
  }
   else 
  {
    Serial.print("Led is off");
    Serial.println();
    return false;
  }
}