#include <Neosegment.h>

/*

This file writes out the first 12 digits of number Pi on 6 Neosegment modules 

*/

#define nDigits 12 // Number of digits you have connected (one Neosegment module consists of 2 digits)
#define PIN 9 // Pin that Neosegment modules are connected to
#define BRIGHTNESS 100 // Brightness value, from 0 to 255

// Initialize Neosegment modules
Neosegment neosegment(nDigits, PIN, BRIGHTNESS);

void setup()
{
  neosegment.begin();
  neosegment.clearAll();
}

void loop()

{
  neosegment.setDigit(0, 3, Wheel(0));
  neosegment.setDigit(1, 1, Wheel(20));
  neosegment.setDigit(2, 4, Wheel(40));
  neosegment.setDigit(3, 1, Wheel(60));
  neosegment.setDigit(4, 5, Wheel(80));
  neosegment.setDigit(5, 9, Wheel(100));
  neosegment.setDigit(6, 2, Wheel(120));
  neosegment.setDigit(7, 6, Wheel(140));
  neosegment.setDigit(8, 5, Wheel(160));
  neosegment.setDigit(9, 3, Wheel(180));
  neosegment.setDigit(10, 5, Wheel(230));
  neosegment.setDigit(12, 8, Wheel(180));
  neosegment.setDigit(13, 9, Wheel(160));
  neosegment.setDigit(14, 7, Wheel(140));
  neosegment.setDigit(15, 9, Wheel(120));
}

/* Returns a hexadecimal value of color wheel, based on input value ranging from 0 to 255 */
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
