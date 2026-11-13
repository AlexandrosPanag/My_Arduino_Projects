/*********
 By Alexandros Panagiotakopoulos
*********/

//Original and enchanced source can be found here: http://www.awam.com.au/design/cc3200-launchxl-thinkspeak-temperature-logger-for-energia/
#ifndef __CC3200R1M1RGC__
// Do not include SPI for CC3200 LaunchPad
#include <SPI.h>
#endif
#include <WiFi.h>
#include <Wire.h>
#include "Adafruit_TMP006.h"
#include <stdlib.h>



Adafruit_TMP006 tmp006(0x41); // start with a diferent i2c address!
void setup() {
//Initialize serial and wait for port to open:
Serial.begin(115200); //set your baud rate to 11520
 
//check if the sensor was connected
if (! tmp006.begin()) {
Serial.println("No sensor found");
while (1);
}

}

void loop() {
// read the temp sensor:
float temp = tmp006.readDieTempC();
Serial.print("Temperature: "); Serial.print(temp); Serial.println("*C");
delay(1000);
}
