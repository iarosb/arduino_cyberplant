/*  [] describe actual setup in README.md
*   [] implement event-based architecture
*/
#include "Led.h"

int danger_LED = 6;
int normal_LED = 4;

int tempPin = 1;
float celsius;

void setup()
{
  ledInit_output(danger_LED);
  ledInit_output(normal_LED);
  Serial.begin(9600);
}

void loop()
{
  isTempSafe_Cel();
  delay(60000);
}

void isTempSafe_Cel() {

  celsius = readThermalSensor_Cel(tempPin);

  if (celsius < 13 || celsius > 25 ) {
    fireEvent_dangerTemp();
  } else {
    fireEvent_normalTemp();
  }
}

//sensor: LM35
float readThermalSensor_Cel(int pin) {

  float val = analogRead(pin);
  float mv = (val/1024.0)*5000;
  float cel = mv/10;

  return cel;
}

void fireEvent_dangerTemp() {

    Serial.print("TEMPRATURE = ");
    Serial.print(celsius);
    Serial.print("*C");
    Serial.println();
    Serial.print("Temp is not ideal for plants :(");
    Serial.println();

    ledOn(danger_LED);
    delay(58000);
    ledOff(danger_LED);
}

void fireEvent_normalTemp() {

    Serial.print("TEMPRATURE = ");
    Serial.print(celsius);
    Serial.print("*C");
    Serial.println();
    Serial.print("Temp is plant-friendly");
    Serial.println();

    ledOn(normal_LED);
    delay(58000);
    ledOff(normal_LED);
}
