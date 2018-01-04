#ifndef Neosegment_h
#define Neosegment_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#endif

#include <Adafruit_NeoPixel.h> // Neosegment library is using Adafruit_NeoPixel library from https://github.com/adafruit/Adafruit_NeoPixel

class Neosegment : public Adafruit_NeoPixel {
  public:
    Neosegment(uint16_t nDigits = 2, uint8_t pin = 9, byte brightness = 100);
    ~Neosegment();
    void begin();
    void clearAll();
    void setDigit(int index, int number, byte red, byte green, byte blue);
    void setDigit(int index, int number, uint32_t color);
    void setDigit(int index, char letter, byte red, byte green, byte blue);
    void setDigit(int index, char letter, uint32_t color);
    void setDigitColor(int index, byte red, byte green, byte blue);
    void setDigitColor(int index, uint32_t);
    void clearDigit(int index);
    void setSegment(int index, byte segment, byte red, byte green, byte blue);
    void setSegment(int index, byte segment, uint32_t color);
    void clearSegment(int index, byte segment);
    bool getSegment(int index, byte segment);
    void setColor(byte red, byte green, byte blue);
    void setColor(uint32_t color);
    void changeColor(byte red, byte green, byte blue);
    void changeColor(uint32_t color);
    void setBrightness(byte brightness);
    byte getBrightness();
  private:
    byte _brightness;
    int _nDigits;

    /*
      Neosegment modules have LEDs in the following order (the number signifies index):
          55555
       4        6
       4        6
       4        6
          33333
       0        2
       0        2
       0        2
          11111
    */

    const bool _numberArray [7][10] = {
      // 0  1  2  3  4  5  6  7  8  9
/* 0 */ {1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
/* 1 */ {1, 0, 1, 1, 0, 1, 1, 0, 1, 1},
/* 2 */ {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
/* 3 */ {0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
/* 4 */ {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
/* 5 */ {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
/* 6 */ {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    };

    const bool _letterArray [7][19] = {
      // A  b  c  d  E  F  g  H  I  J, L, n, o, P, q, r, S, t, U,
/* 0 */ {1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1},
/* 1 */ {0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
/* 2 */ {1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
/* 3 */ {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
/* 4 */ {1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1},
/* 5 */ {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
/* 6 */ {1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    };

    const String _letterIndexes = "abcdefghijlnopqrstu";

    byte* _rArray;
    byte* _gArray;
    byte* _bArray;
};

#endif
