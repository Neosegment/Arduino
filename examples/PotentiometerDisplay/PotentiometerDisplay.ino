#include <Neosegment.h>

/*

This code can be used to display a value from a potentiometer, dynamically changing color depending on the value
2 Neosegment modules are used to display a number from 0 to 1023

Connect potentiometer to Arduino Uno or similar as follows:

5V    A0     GND
|      |      |
 ---[  *  ]--

This code uses an array of readings to display an average reading that avoids most of the flickering
The code could be improved by only refreshing the digit that changes, instead of all digits
*/


int potpin = 0;       // analog pin used to connect the potentiometer
int sensorReading = 0;    // variable to read the value from the analog pin
int oldSensorReading = 0; // variable to store previous reading
int digitBuffer;
int digitIndex;

#define nDigits 4
#define PIN 9 // Which pin the Neosegment modules are connected to

const int numReadings = 10; // how many readings to remember

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // average value

Neosegment neosegment(nDigits, PIN, 100);

void setup()
{
  Serial.begin(115200);
  neosegment.begin();
  neosegment.clearAll();

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop(){
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(potpin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;

  sensorReading = average;

  if (oldSensorReading != sensorReading) {
    oldSensorReading = sensorReading;
  }

  // If the sensor reading is below 1000, make sure the 0-th digit is off
  if(sensorReading < 1000) {
    neosegment.clearDigit(0);
  }

  // If the sensor reading is below 100, make sure the 0-th and 1-st digits are off
  if(sensorReading < 100) {
    neosegment.clearDigit(0);
    neosegment.clearDigit(1);
  }

  // If the sensor reading is below 100, make sure the 0-th, 1-st and 2-nd digits are off
  if(sensorReading < 10) {
    neosegment.clearDigit(0);
    neosegment.clearDigit(1);
    neosegment.clearDigit(2);
  }

  digitIndex = nDigits - 1;
  digitBuffer = sensorReading; // Start with the whole string of numbers

  // Display every digit from the sensor reading on appropriate Neosegment Digit
  while (digitBuffer > 0)
  {
      int digit = digitBuffer % 10;
      // Write digit to Neosegment display in color that corresponds to the sensor reading
      neosegment.setDigit( digitIndex, digit,  Wheel(map(sensorReading, 0, 1024, 0, 255)));

      digitBuffer /= 10;
      digitIndex--;
  }

  delay(50);
}

// Helper function to return a color on a color wheel
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return neosegment.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return neosegment.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return neosegment.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
