#include "Neosegment.h"

/* 
  Instantiates the Neosgment class with some reasonable defaults 
*/
Neosegment::Neosegment(uint16_t nDigits, uint8_t pin, byte brightness)
  : Adafruit_NeoPixel(7 * nDigits, pin, NEO_GRB + NEO_KHZ800),
  _brightness(brightness), _nDigits(nDigits)
{
  _rArray = new byte[7 * nDigits]; // Array that stores red values of each LED in the strip
  _gArray = new byte[7 * nDigits]; // Array that stores green values of each LED
  _bArray = new byte[7 * nDigits]; // Array that stores blue values of each LED
}

/* Destructor */
Neosegment::~Neosegment()
{
  delete [] _rArray;
  delete [] _gArray;
  delete [] _bArray;
}

/* 
  Uses Adafruit library to create a new strip definition and set it's brightness to desired value 
*/
void Neosegment::begin()
{
  // Init LED strip, set brightness
  Adafruit_NeoPixel::begin();
  Adafruit_NeoPixel::setBrightness(_brightness);
}

/* 
  Clears all LEDs on all Neosegment modules 
*/
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

/* 
  Sets a digit with specified index to specified numerical value and a color provided as three values of RGB mixing 
*/
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

/* 
  Sets a digit with specified index to specified numerical value and a color provided as single hexadecimal value 
*/
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

/* 
  Sets a digit with specified index to specified letter with a color provided as three values of RGB mixing 
*/
void Neosegment::setDigit(int index, char letter, byte red, byte green, byte blue)
{ 
  int letterIndex = _letterIndexes.indexOf(tolower(letter));
  for (int segm = 7 * index; segm < 7 * index + 7; segm++) {

    _rArray[segm] = 0;
    _gArray[segm] = 0;
    _bArray[segm] = 0;

    if (_letterArray[segm % 7][letterIndex]) {
      _rArray[segm] = red;
      _gArray[segm] = green;
      _bArray[segm] = blue;
    }
    setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
  }
  show();
}

/* 
  Sets a digit with specified index to specified letter with a color provided as single hexadecimal value 
*/
void Neosegment::setDigit(int index, char letter, uint32_t color)
{ 
  int letterIndex = _letterIndexes.indexOf(tolower(letter));
  for (int segm = 7 * index; segm < 7 * index + 7; segm++) {

    _rArray[segm] = 0;
    _gArray[segm] = 0;
    _bArray[segm] = 0;

    if (_letterArray[segm % 7][letterIndex]) {
      _rArray[segm] = (uint8_t)(color >> 16);
      _gArray[segm] = (uint8_t)(color >> 8);
      _bArray[segm] = (uint8_t)color;
    }
    setPixelColor(segm, _rArray[segm], _gArray[segm],  _bArray[segm]);
  }
  show();
}

/*
  Clears out a digit with specified index
*/
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

/* 
  Sets individual specified segment on module with a specified index to a color provided as three values of RGB mixing 
*/
void Neosegment::setSegment(int index, byte segment, byte red, byte green, byte blue)
{
  int segm = 7 * index + segment;
  _rArray[segm] = red;
  _gArray[segm] = green;
  _bArray[segm] = blue;
  setPixelColor(segm, red, green, blue);
  show();
}

/* 
  Sets individual specified segment on module with a specified index to a color provided a single hexadecimal value 
*/
void Neosegment::setSegment(int index, byte segment, uint32_t color)
{
  int segm = 7 * index + segment;
  _rArray[segm] = (uint8_t)(color >> 16);
  _gArray[segm] = (uint8_t)(color >> 8);
  _bArray[segm] = (uint8_t)color;

  setPixelColor(segm, _rArray[segm], _gArray[segm], _bArray[segm]);
  show();
}

/*
  Clears out a segment with specified index
 */
void Neosegment::clearSegment(int index, byte segment)
{
  int segm = 7 * index + segment;
  _rArray[segm] = 0;
  _gArray[segm] = 0;
  _bArray[segm] = 0;
  setPixelColor(segm, 0, 0, 0);
  show();
}

/*
  Returns true in case a segment is currently lit
 */
bool Neosegment::getSegment(int index, byte segment)
{
  int segm = 7 * index + segment;
  return (_rArray[segm] > 0) || (_gArray[segm] > 0) || (_bArray[segm] > 0);
}

/* 
  Sets color of the whole LED strip with color provided as three values of RGB mixing 
*/
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

/* 
  Sets color of the whole LED strip with color provided as singe hexadecimal value 
*/
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

/* 
  Changes color of all currently lit segments on the whole strip to a color provided as three values of RGB mixing 
*/
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

/* 
  Changes color of all currently lit segments on the whole strip to a color provided as a single hexadecimal value 
*/
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

/* 
  Changes color of all currently lit segments on the digit with a specified index to a color provided as three values of RGB mixing 
*/
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

/* 
  Changes color of all currently lit segments on the digit with a specified index to a color provided as hexadecimal value 
*/
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

/* 
  Sets brightness of the strip.
    WARNING: do not use this function to animate brightness. Only use it once or twice in total to set brightness of the whole strip. Trying to use it too frequently will result in loss of code stability.
*/
void Neosegment::setBrightness(byte brightness){
  _brightness = brightness;
  Adafruit_NeoPixel::setBrightness(brightness);
  show();
}

/* 
  Returns brightness of the strip.
*/
byte Neosegment::getBrightness() {
  return _brightness;
}
