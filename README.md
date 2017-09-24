# Arduino library and examples

This repository contains the library and simple demos for Neosegment Digit modules.

## Connecting the modules 

By default the Neosegment Data pin should be connected to pin 9 on Arduino. 

Unless you set all segments to white at once, it should be safe to use +5V and GND of the Arduino to light up 1-5 modules (0-10 digits) in some single color on low brightness (values 1-100 for the brightness). If you plan to use a lot of color mixing on the whole strip of modules, be sure to use additional 5V power supply.

## Installing the library

If you are using Arduino IDE, you should be able to open `main.ino` file as long as you have `Neosegment.cpp` and `Neosegment.h` file in the same folder.

The `main.ino` file has a few demos of some animations, text and number displays. 

Note: I use [PlatformIO](http://platformio.org/) for fast cross - compilation between Arduino, ESP8266 and similar architectures. It is highly recommended you check it out to save time compiling your Arduino projects.

## Neosegment library set up

There are three main parameters that you need to set when using Neosegment library in your projects: 
- Which pin the modules are connected to
- How many digits you have available (each module contains 2 digits)
- What brightness to set the modules to

Here is a snippet of code that you can use in your projects that use Neosegment library:

```
#include "Neosegment.h"
#define nDigits 6 // Each module has 2 digits. If you have 3 modules, set nDigits to 6
#define PIN 9 // Which Arduino pin is the Neosegment data pin connected to
#define LEDbrightness 100 // Brightness is a value from 0 to 255

Neosegment neosegment(nDigits, PIN, LEDbrightness); 

void setup() {
  neosegment.begin();
  neosegment.clearAll(); // Make sure to clear all modules
}
```

## Library functions

There are two main functions for displaying things on Neosegment:
- `setDigit` (could be either a number or a letter)
- `setSegment`

Each "digit" represents individual digit on the Neosegment modules, with the index starting at **0**(zero).

To set the first digit on the first module to display number `6` in color red, you would do one of the following:

```
neosegment.setDigit(0, 6, 255, 0, 0);
// same as
neosegment.setDigit(0, 6, 0xFF0000);

```

You can also set a digit to display one of the 19 letters that work well on seven segment displays. For example if you wanted to write the word "colors" on the first 3 Neosegment modules in different colors, you would do this:

```
neosegment.setDigit(0, 'c', 0xFF0000);
neosegment.setDigit(1, 'o', 0xFFFF00);
neosegment.setDigit(2, 'l', 0xFF00FF);
neosegment.setDigit(3, 'o', 0x00FF00);
neosegment.setDigit(4, 'r', 0x0000FF);
neosegment.setDigit(5, 's', 0xFFFFFF);
  
```
 
