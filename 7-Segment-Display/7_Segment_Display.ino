/*********
 By Alexandros Panagiotakopoulos
*********/

#include "SevSeg.h"
/*
SevSeg
Display

Turns your Arduino into a seven segment display controller!
Use it to easily display numbers on your seven segment display without any additional hardware. Supports common cathode and common anode displays, the use of switching transistors, decimal numbers, hexadecimal numbers, and alphanumeric characters.

Author: Dean Reading

Maintainer: Dean Reading

*/

SevSeg sevseg;

void setup()
{
  //Set to 1 for single digit display
  byte numDigits = 1;

  //defines common pins while using multi-digit display. Left empty as we have a single digit display
  byte digitPins[] = {};
  //Defines arduino pin A, B, C, D, E, F, G, DP
  byte segmentPins[] = {7, 6, 4, 2, 1, 9, 10, 5};
  bool resistorsOnSegments = true;

  //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);

  sevseg.setBrightness(90);
}

void loop()
{ 
   //Display numbers one by one with 1 second delay
   for(int i = 0; i < 10; i++)
   {
     sevseg.setNumber(i);
     sevseg.refreshDisplay(); 
     delay(1000);
   }
}
