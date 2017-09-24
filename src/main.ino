#include <Neosegment.h>
#define SERIAL_BAUD 115200
#define nDigits 12
#define PIN 9

int mode = 0; // Change this to any number between 0 and 7 to see different animations

Neosegment neosegment(nDigits, PIN, 40);
uint16_t i, j;

void setup() {
  Serial.begin(SERIAL_BAUD);

  neosegment.begin();
  neosegment.clearAll();
}

void loop() {

  switch (mode) {
    // Fun loading loop
    case 0:
    {
      for (int loadingLoop = 0; loadingLoop < 10; loadingLoop++) {
        for (int colorLoop = 0; colorLoop < 255; colorLoop++) {
          neosegment.setSegment(0, 0, Wheel((colorLoop*9 + 31) & 255));
          neosegment.setSegment(0, 1, Wheel((colorLoop*9 + 31*2) & 255));
          neosegment.setSegment(1, 1, Wheel((colorLoop*9 + 31*3) & 255));
          neosegment.setSegment(1, 2, Wheel((colorLoop*9 + 31*4) & 255));
          neosegment.setSegment(1, 6, Wheel((colorLoop*9 + 31*5) & 255));
          neosegment.setSegment(1, 5, Wheel((colorLoop*9 + 31*6) & 255));
          neosegment.setSegment(0, 5, Wheel((colorLoop*9 + 31*7) & 255));
          neosegment.setSegment(0, 4, Wheel((colorLoop*9 + 31*8) & 255));
          
          neosegment.setSegment(0, 2, Wheel((colorLoop*9 + 31*3) & 255));
          neosegment.setSegment(0, 3, Wheel((colorLoop*9 + 31*4) & 255));
          neosegment.setSegment(0, 6, Wheel((colorLoop*9 + 31*5) & 255));
          neosegment.setSegment(1, 0, Wheel((colorLoop*9 + 31*6) & 255));
          neosegment.setSegment(1, 3, Wheel((colorLoop*9 + 31*7) & 255));
          neosegment.setSegment(1, 4, Wheel((colorLoop*9 + 31*8) & 255));
          delay(10);
        }
      }
      break;
    }
    // Countdown from 10 to 0
    case 1:
    {
      neosegment.setSegment(0, 3, 255, 255, 255);
      neosegment.setSegment(1, 3, 255, 255, 255);
      neosegment.setSegment(4, 3, 255, 255, 255);
      neosegment.setSegment(5, 3, 255, 255, 255);

      neosegment.setDigit(2, 1, 255, 255, 255);
      neosegment.setDigit(3, 0, 255, 255, 255);

      delay(500);
      neosegment.setDigit(2, 0, 255, 255, 0);
      neosegment.setDigit(3, 9, 255, 255, 0);

      delay(500);
      neosegment.setDigit(2, 0, 66, 109, 125);
      neosegment.setDigit(3, 8, 66, 109, 125);

      delay(500);
      neosegment.setDigit(2, 0, 155, 32, 120);
      neosegment.setDigit(3, 7, 155, 32, 120);

      delay(500);
      neosegment.setDigit(2, 0, 0, 40, 200);
      neosegment.setDigit(3, 6, 0, 40, 200);

      delay(500);
      neosegment.setDigit(2, 0, 255, 0, 0);
      neosegment.setDigit(3, 5, 255, 0, 0);

      delay(500);

      neosegment.setDigit(2, 0, 44, 66, 193);
      neosegment.setDigit(3, 4, 44, 66, 193);
      delay(500);

      neosegment.setDigit(2, 0, 148, 44, 193);
      neosegment.setDigit(3, 3, 148, 44, 193);
      delay(500);

      neosegment.setDigit(2, 0, 56, 193, 44);
      neosegment.setDigit(3, 2, 56, 193, 44);
      delay(500);

      neosegment.setDigit(2, 0, 140, 0, 255);
      neosegment.setDigit(3, 1, 140, 0, 255);
      delay(500);

      neosegment.setDigit(2, 0, 100, 100, 255);
      neosegment.setDigit(3, 0, 100, 100, 255);
      delay(500);

      neosegment.clearAll();
      break;
    }
    // Writes out HELLO COLORS
    case 2:
    {
      // H
      neosegment.setSegment(0, 0, 255, 0, 0);
      neosegment.setSegment(0, 2, 255, 0, 0);
      neosegment.setSegment(0, 3, 255, 0, 0);
      neosegment.setSegment(0, 4, 255, 0, 0);
      neosegment.setSegment(0, 6, 255, 0, 0);
      delay(80);


      // E
      neosegment.setSegment(1, 0, 0, 0, 255);
      neosegment.setSegment(1, 1, 0, 0, 255);
      neosegment.setSegment(1, 3, 0, 0, 255);
      neosegment.setSegment(1, 4, 0, 0, 255);
      neosegment.setSegment(1, 5, 0, 0, 255);
      delay(80);


      // L
      neosegment.setSegment(2, 0, 122, 0, 255);
      neosegment.setSegment(2, 1, 122, 0, 255);
      neosegment.setSegment(2, 4, 122, 0, 255);
      delay(80);


      // L
      neosegment.setSegment(3, 0, 24, 0, 155);
      neosegment.setSegment(3, 1, 24, 0, 155);
      neosegment.setSegment(3, 4, 24, 0, 155);
      delay(80);

      // O
      neosegment.setSegment(4, 0, 24, 0, 155);
      neosegment.setSegment(4, 1, 24, 0, 155);
      neosegment.setSegment(4, 2, 24, 0, 155);
      neosegment.setSegment(4, 4, 24, 0, 155);
      neosegment.setSegment(4, 5, 24, 0, 155);
      neosegment.setSegment(4, 6, 24, 0, 155);
      delay(300);

      for (int digit = 0; digit < nDigits; digit++) {
         neosegment.clearDigit(digit);
         delay(50);
      }

      // C
      neosegment.setSegment(0, 0, 255, 0, 250);
      neosegment.setSegment(0, 1, 255, 0, 250);
      neosegment.setSegment(0, 4, 255, 0, 250);
      neosegment.setSegment(0, 5, 255, 0, 250);
      delay(80);

      // O
      neosegment.setSegment(1, 0, 0, 0, 255);
      neosegment.setSegment(1, 1, 0, 0, 255);
      neosegment.setSegment(1, 2, 0, 0, 255);
      neosegment.setSegment(1, 4, 0, 0, 255);
      neosegment.setSegment(1, 5, 0, 0, 255);
      neosegment.setSegment(1, 6, 0, 0, 255);
      delay(80);

      // L
      neosegment.setSegment(2, 0, 122, 0, 255);
      neosegment.setSegment(2, 1, 122, 0, 255);
      neosegment.setSegment(2, 4, 122, 0, 255);
      delay(80);

      // O
      neosegment.setSegment(3, 0, 0, 255, 0);
      neosegment.setSegment(3, 1, 0, 255, 0);
      neosegment.setSegment(3, 2, 0, 255, 0);
      neosegment.setSegment(3, 4, 0, 255, 0);
      neosegment.setSegment(3, 5, 0, 255, 0);
      neosegment.setSegment(3, 6, 0, 255, 0);
      delay(80);

      // R
      neosegment.setSegment(4, 0, 255, 255, 255);
      neosegment.setSegment(4, 3, 255, 255, 255);

      delay(80);

      // S
      neosegment.setSegment(5, 1, 255, 0 , 0);
      neosegment.setSegment(5, 2, 255, 0 , 0);
      neosegment.setSegment(5, 3, 255, 0 , 0);
      neosegment.setSegment(5, 4, 255, 0 , 0);
      neosegment.setSegment(5, 5, 255, 0 , 0);

      delay(1500);

      neosegment.clearAll();
        break;
    }
    // Animation from left to right
    case 3:
    {

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

      delay(1000);
      break;
    }
    case 4:
    {
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

      break;
    }

    // Numbers with changing colors
    case 5:
    {
      for (int digit = 0; digit < nDigits; digit++) {
        neosegment.setDigit(digit, digit, Wheel((digit*40) & 255));
      }
      break;
    }

    // Snake 
    case 6:
    {
      for (int loadingLoop = 0; loadingLoop < 10; loadingLoop++) {
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
      break;
    }
    default:

    break;
  }
}

void setLetter(int index, char letter, uint32_t color) {
  switch (letter) {
    case 'a':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 5, color);
      neosegment.setSegment(index, 6, color);
      break;
    case 'b':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      break;
    case 'c':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 3, color);
      break;
    case 'd':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 6, color);
      break;
    case 'e':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 5, color);
      break;
    case 'f':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 5, color);
      break;
    case 'g':
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 5, color);
      neosegment.setSegment(index, 6, color);
      break;
    case 'h':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 6, color);
      break;
    case 'k':
      break;
    case 'p':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 5, color);
      neosegment.setSegment(index, 6, color);
      break;
    case 'l':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 4, color);
      break;
    case 'n':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      break;
    case 's':
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 2, color);
      neosegment.setSegment(index, 3, color);
      neosegment.setSegment(index, 4, color);
      neosegment.setSegment(index, 5, color);
      break;
    case 'u':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 1, color);
      neosegment.setSegment(index, 2, color);
      break;  
    case 'r':
      neosegment.setSegment(index, 0, color);
      neosegment.setSegment(index, 3, color);
      break;
    default:
      break;
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    //Serial.print(neosegment.Color(255 - WheelPos * 3, 0, WheelPos * 3));
    return neosegment.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return neosegment.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return neosegment.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
