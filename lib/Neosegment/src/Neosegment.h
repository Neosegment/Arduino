#ifndef Neosegment_h
#define Neosegment_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h> //Using Adafruit_NeoPixel library from https://github.com/adafruit/Adafruit_NeoPixel

class Neosegment : public Adafruit_NeoPixel {
  public:
    Neosegment(uint16_t nDigits, uint8_t pin = 12, byte brightness = 100);
    ~Neosegment();
    void begin();
    void clearAll();
    void setDigit(int index, int number, byte red, byte green, byte blue);
    void setDigit(int index, int number, uint32_t color);
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

    /*
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

    const bool _letterArray [7][10] = {
      // A, B, C, d, E, F, g, H, I, J ,K, L, m, N, o, P, q, r, S, t, U, v, X, y, z

      // A  b  c  d  E  F  g  H  I  J, L, n, o, P, q, r, S, t, U,
/* 0 */ {1, 1, 1, 1, 1, 1, 0, 1, 0, 0},
/* 1 */ {0, 1, 1, 1, 1, 0, 1, 0, 0, 1},
/* 2 */ {1, 1, 0, 1, 0, 0, 1, 1, 1, 1},
/* 3 */ {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
/* 4 */ {1, 0, 0, 0, 1, 1, 1, 1, 0, 0},
/* 5 */ {1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
/* 6 */ {1, 0, 0, 1, 0, 0, 1, 1, 1, 1},
    };

    byte* _rArray;
    byte* _gArray;
    byte* _bArray;
};

#endif
