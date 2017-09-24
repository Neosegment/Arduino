#include "Neosegment.h"

Neosegment::Neosegment(uint16_t nDigits, uint8_t pin, byte brightness)
  : Adafruit_NeoPixel(7 * nDigits, pin, NEO_GRB + NEO_KHZ800),
  _brightness(brightness), _nDigits(nDigits)
{
  _rArray = new byte[7 * nDigits]; // Array that stores red values of each LED
  _gArray = new byte[7 * nDigits]; // Array that stores green values of each LED
  _bArray = new byte[7 * nDigits]; // Array that stores blue values of each LED
}

Neosegment::~Neosegment()
{
  delete [] _rArray;
  delete [] _gArray;
  delete [] _bArray;
}

void Neosegment::begin()
{
  // Init led strip, set brightness
  Adafruit_NeoPixel::begin();
  Adafruit_NeoPixel::setBrightness(_brightness);
}

void Neosegment::clearAll()
{
  for (int segm = 0; segm < 7 * _nDigits; segm++) {
    _rArray[segm] = 0;
    _gArray[segm] = 0;
    _bArray[segm] = 0;
    setPixelColor(segm, 0, 0, 0);
  }
  show();
}

void Neosegment::setDigit(int index, int number, byte red, byte green, byte blue)
{
  if (number < 0 || number > 9) return;
  for (int segm = 7 * index; segm < 7 * index + 7; segm++) {

    _rArray[segm] = 0;
    _gArray[segm] = 0;
    _bArray[segm] = 0;

    if (_numberArray[segm % 7][number]) {
      _rArray[segm] = red;
      _gArray[segm] = green;
      _bArray[segm] = blue;
    }
    setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
  }
  show();
}

void Neosegment::setDigit(int index, int number, uint32_t color)
{
  if (number < 0 || number > 9) return;
  for (int segm = 7 * index; segm < 7 * index + 7; segm++) {

    _rArray[segm] = 0;
    _gArray[segm] = 0;
    _bArray[segm] = 0;

    if (_numberArray[segm % 7][number]) {
      _rArray[segm] = (uint8_t)(color >> 16);
      _gArray[segm] = (uint8_t)(color >> 8);
      _bArray[segm] = (uint8_t)color;
    }
    setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
  }
  show();
}

void Neosegment::clearDigit(int index)
{
  for (int segm = 7 * index; segm < 7 * index + 7; segm++) {
    _rArray[segm] = 0;
    _gArray[segm] = 0;
    _bArray[segm] = 0;
    setPixelColor(segm, 0, 0, 0);
  }
  show();
}

void Neosegment::setSegment(int index, byte segment, byte red, byte green, byte blue)
{
  int segm = 7 * index + segment;
  _rArray[segm] = red;
  _gArray[segm] = green;
  _bArray[segm] = blue;
  setPixelColor(segm, red, green, blue);
  show();
}

void Neosegment::setSegment(int index, byte segment, uint32_t color)
{
  int segm = 7 * index + segment;
  _rArray[segm] = (uint8_t)(color >> 16);
  _gArray[segm] = (uint8_t)(color >> 8);
  _bArray[segm] = (uint8_t)color;

  setPixelColor(segm, _rArray[segm], _gArray[segm], _bArray[segm]);
  show();
}

void Neosegment::clearSegment(int index, byte segment)
{
  int segm = 7 * index + segment;
  _rArray[segm] = 0;
  _gArray[segm] = 0;
  _bArray[segm] = 0;
  setPixelColor(segm, 0, 0, 0);
  show();
}

bool Neosegment::getSegment(int index, byte segment)
{
  int segm = 7 * index + segment;
  return (_rArray[segm] > 0) || (_gArray[segm] > 0) || (_bArray[segm] > 0);
}

void Neosegment::setColor (byte red, byte green, byte blue)
{
  for (int segm = 0; segm < 7 * _nDigits; segm++) {
    _rArray[segm] = red;
    _gArray[segm] = green;
    _bArray[segm] = blue;
    setPixelColor(segm, red, green, blue);
  }
  show();
}

void Neosegment::setColor(uint32_t color)
{
  for (int segm = 0; segm < 7 * _nDigits; segm++) {
    _rArray[segm] = (uint8_t)(color >> 16);
    _gArray[segm] = (uint8_t)(color >> 8);
    _bArray[segm] = (uint8_t)color;
    setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
  }
  show();
}

void Neosegment::changeColor(byte red, byte green, byte blue)
{
  for (int segm = 0; segm < 7 * _nDigits; segm++) {
    if ((_rArray[segm] != 0) || (_gArray[segm] != 0) || (_bArray[segm] != 0)) {
      _rArray[segm] = red;
      _gArray[segm] = green;
      _bArray[segm] = blue;
      setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
    }
  }
  show();
}

void Neosegment::changeColor(uint32_t color)
{
  for (int segm = 0; segm < 7 * _nDigits; segm++) {
    if ((_rArray[segm] != 0) || (_gArray[segm] != 0) || (_bArray[segm] != 0)) {
      _rArray[segm] = (uint8_t)(color >> 16);
      _gArray[segm] = (uint8_t)(color >> 8);
      _bArray[segm] = (uint8_t)color;
      setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
    }
  }
  show();
}

void Neosegment::setDigitColor(int index, byte red, byte green, byte blue)
{
  for (int segm = 7*index; segm < 7*index + 7; segm++) {
    if ((_rArray[segm] != 0) || (_gArray[segm] != 0) || (_bArray[segm] != 0)) {
      _rArray[segm] = red;
      _gArray[segm] = green;
      _bArray[segm] = blue;
      setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
    }
  }
  show();
}

void Neosegment::setDigitColor(int index, uint32_t color)
{
  for (int segm = 7*index; segm < 7*index + 7; segm++) {
    if ((_rArray[segm] != 0) || (_gArray[segm] != 0) || (_bArray[segm] != 0)) {
      _rArray[segm] = (uint8_t)(color >> 16);
      _gArray[segm] = (uint8_t)(color >> 8);
      _bArray[segm] = (uint8_t)color;
      setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
    }
  }
  show();
}

void Neosegment::setBrightness(byte brightness){
  _brightness = brightness;
  Adafruit_NeoPixel::setBrightness(brightness);
  show();
}

byte Neosegment::getBrightness() {
  return _brightness;
}
