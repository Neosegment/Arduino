#include <Neosegment.h>

#define nDigits 12 // Number of digits you have connected (one Neosegment module consists of 2 digits)
#define PIN 9 // Pin that Neosegment modules are connected to
#define BRIGHTNESS 100 // Brightness value, from 0 to 255

// Initialize Neosegment modules
Neosegment neosegment(nDigits, PIN, BRIGHTNESS);

uint16_t i, j;

void setup() {
  neosegment.begin();
  neosegment.clearAll();
}

void loop() {
  // Fun loading loop with a color wheel rotation
  for (int loadingLoop = 0; loadingLoop < 2; loadingLoop++) {
    for (int colorLoop = 0; colorLoop < 255; colorLoop++) {
      neosegment.setSegment(0, 0, Wheel((colorLoop*9 + 31) & 255));
      neosegment.setSegment(0, 1, Wheel((colorLoop*9 + 31*2) & 255));
      neosegment.setSegment(1, 1, Wheel((colorLoop*9 + 31*3) & 255));
      neosegment.setSegment(1, 2, Wheel((colorLoop*9 + 31*4) & 255));
      neosegment.setSegment(1, 6, Wheel((colorLoop*9 + 31*5) & 255));
      neosegment.setSegment(1, 5, Wheel((colorLoop*9 + 31*6) & 255));
      neosegment.setSegment(0, 5, Wheel((colorLoop*9 + 31*7) & 255));
      neosegment.setSegment(0, 4, Wheel((colorLoop*9 + 31*8) & 255));
      delay(10);
    }
  }
  neosegment.clearAll();

  // Writes out "HELLO COLORS"
  neosegment.setDigit(0, 'h', 0xFF0000);
  delay(50);
  neosegment.setDigit(1, 'e', 0xFFFF00);
  delay(50);
  neosegment.setDigit(2, 'l', 0xFF00FF);
  delay(50);
  neosegment.setDigit(3, 'l', 0x00FF00);
  delay(50);
  neosegment.setDigit(4, 'o', 0x0000FF);

  delay(500);

  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.clearDigit(digit);
     delay(50);
  }

  neosegment.setDigit(0, 'c', 0xFF0000);
  delay(50);
  neosegment.setDigit(1, 'o', 0xFFFF00);
  delay(50);
  neosegment.setDigit(2, 'l', 0xFF00FF);
  delay(50);
  neosegment.setDigit(3, 'o', 0x00FF00);
  delay(50);
  neosegment.setDigit(4, 'r', 0x0000FF);
  delay(50);
  neosegment.setDigit(5, 's', 0xFFFFFF);

  delay(1500);

  neosegment.clearAll();

  // Countdown from 10 to 0
  neosegment.setSegment(0, 3, 255, 255, 255);
  neosegment.setSegment(1, 3, 255, 255, 255);
  neosegment.setSegment(4, 3, 255, 255, 255);
  neosegment.setSegment(5, 3, 255, 255, 255);

  neosegment.setDigit(2, 1, 255, 255, 255);
  neosegment.setDigit(3, 0, 255, 255, 255);

  delay(1000);
  neosegment.setDigit(2, 0, 255, 255, 0);
  neosegment.setDigit(3, 9, 255, 255, 0);

  delay(1000);
  neosegment.setDigit(2, 0, 66, 109, 125);
  neosegment.setDigit(3, 8, 66, 109, 125);

  delay(1000);
  neosegment.setDigit(2, 0, 155, 32, 120);
  neosegment.setDigit(3, 7, 155, 32, 120);

  delay(1000);
  neosegment.setDigit(2, 0, 0, 40, 200);
  neosegment.setDigit(3, 6, 0, 40, 200);

  delay(1000);
  neosegment.setDigit(2, 0, 255, 0, 0);
  neosegment.setDigit(3, 5, 255, 0, 0);

  delay(1000);

  neosegment.setDigit(2, 0, 44, 66, 193);
  neosegment.setDigit(3, 4, 44, 66, 193);
  delay(1000);

  neosegment.setDigit(2, 0, 148, 44, 193);
  neosegment.setDigit(3, 3, 148, 44, 193);
  delay(1000);

  neosegment.setDigit(2, 0, 56, 193, 44);
  neosegment.setDigit(3, 2, 56, 193, 44);
  delay(1000);

  neosegment.setDigit(2, 0, 140, 0, 255);
  neosegment.setDigit(3, 1, 140, 0, 255);
  delay(1000);

  neosegment.setDigit(2, 0, 100, 100, 255);
  neosegment.setDigit(3, 0, 100, 100, 255);
  delay(1000);

  neosegment.clearAll();

  // Animation from left to right
  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.setSegment(digit, 1, Wheel((digit*40) & 255));
     neosegment.setSegment(digit, 5, Wheel((digit*40) & 255));
     delay(50);
  }

  delay(50);

  for (int digit = nDigits; digit >= 0; digit--) {
     neosegment.setSegment(digit, 3, Wheel((digit*40) & 255));
     delay(50);
  }

  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.setSegment(digit, 0, Wheel((digit*40) & 255));
     neosegment.setSegment(digit, 4, Wheel((digit*40) & 255));
     delay(50);
     neosegment.setSegment(digit, 2, Wheel((digit*40) & 255));
     neosegment.setSegment(digit, 6, Wheel((digit*40) & 255));
     delay(50);
  }

  for (int digit = nDigits; digit >= 0; digit--) {
     neosegment.clearSegment(digit, 2);
     neosegment.clearSegment(digit, 6);
     delay(50);
     neosegment.clearSegment(digit, 1);
     neosegment.clearSegment(digit, 3);
     neosegment.clearSegment(digit, 5);
     delay(50);
     neosegment.clearSegment(digit, 0);
     neosegment.clearSegment(digit, 4);
     delay(50);
  }

  neosegment.clearAll();

  delay(1000);

  // Simple numbers with the same colors
  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.setSegment(digit, 1, 255, 0, 0);
     delay(40);
     neosegment.setSegment(digit, 2, 255, 0, 0);
     delay(40);
     neosegment.setSegment(digit, 6, 255, 0, 0);
     delay(40);
     neosegment.setSegment(digit, 5, 255, 0, 0);
     delay(40);
     neosegment.setSegment(digit, 4, 255, 0, 0);
     delay(40);
     neosegment.setSegment(digit, 0, 255, 0, 0);
     delay(40);
  }

  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.setSegment(digit, 1, 0, 255, 0);
     delay(40);
     neosegment.setSegment(digit, 2,  0, 255, 0);
     delay(40);
     neosegment.setSegment(digit, 6,  0, 255, 0);
     delay(40);
     neosegment.setSegment(digit, 5,  0, 255, 0);
     delay(40);
     neosegment.setSegment(digit, 4,  0, 255, 0);
     delay(40);
     neosegment.setSegment(digit, 0,  0, 255, 0);
     delay(40);
  }

  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.setSegment(digit, 1, 0,0,255);
     delay(40);
     neosegment.setSegment(digit, 2,  0,0,255);
     delay(40);
     neosegment.setSegment(digit, 6,  0,0,255);
     delay(40);
     neosegment.setSegment(digit, 5,  0,0,255);
     delay(40);
     neosegment.setSegment(digit, 4,  0,0,255);
     delay(40);
     neosegment.setSegment(digit, 0,  0,0,255);
     delay(40);
  }

  // Numbers with various colors
  for (int digit = 0; digit < nDigits; digit++) {
    neosegment.setDigit(digit, digit, Wheel((digit*40) & 255));
  }

  for (int digit = 0; digit < nDigits; digit++) {
     neosegment.clearDigit(digit);
     delay(50);
  }

  delay(4000);

  neosegment.clearAll();
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
