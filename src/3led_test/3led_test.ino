#include "Led.h"

int indicator = 13;

int hot_LED = 6;
int normal_LED = 4;
int cold_LED = 2;

void setup()
{
  ledInit_output(indicator);
  ledInit_output(hot_LED);
  ledInit_output(normal_LED);
  ledInit_output(cold_LED);
}

void loop()
{
  testTimes(10);
}


void testTimes(int n)
{
  for (int i = 0; i <= n; i++){
    signal();
  }
}

void signal()
{
  blink(indicator);
  blink(hot_LED);
  blink(normal_LED);
  blink(cold_LED);
}

void blink(int led)
{
    ledOn(led);
    delay(3000);
    ledOff(led);
}
