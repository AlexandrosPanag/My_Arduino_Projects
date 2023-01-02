/*********
 By Alexandros Panagiotakopoulos - alexandrospanag.github.io
*********/

#include <LiquidCrystal_I2C.h>
/*
Author
Frank de Brabander
Maintainer
Marco Schwartz
Website
https://github.com/marcoschwartz/LiquidCrystal_I2C
avr
*/

#include "dht.h" 
/*!
 *  @file DHT.h
 *
 *  This is a library for DHT series of low cost temperature/humidity sensors.
 *
 *  You must have Adafruit Unified Sensor Library library installed to use this
 * class.
 *
 *  Adafruit invests time and resources providing this open source code,
 *  please support Adafruit andopen-source hardware by purchasing products
 *  from Adafruit!
 *
 *  Written by Adafruit Industries.
 *
 *  MIT license, all text above must be included in any redistribution
 */

dht DHT;

int sensorValue;

// set the LCD number of columns and rows
int time_count_second=0; //Declaring a time counter for each second
int lcdColumns = 16; //initialize the lines of the lcd (columns)
int lcdRows = 2; //initialize the rows

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  Serial.begin(9600); //begin the serial display with 9600 baud rate , we can view the results on the serial monitor
  //if the serial shows 0 it means that something isn't connected properly
}

void loop(){
  DHT.read11(4); //read from D4 the DHT11 Sensor
  Serial.print("Current humidity = "); //Serial Display the humidity levels
  Serial.print(DHT.humidity); //print the value from the sensor
  Serial.println(); //print a new line for cosmetic reasons
  sensorValue = analogRead(0);       // read analog input pin 0
  Serial.print("AirQua="); //print AirQua which stands for AirQuality
  Serial.print(sensorValue, DEC);               // prints the value read
  Serial.println(" PPM"); //PPM value
  //random number generator
   time_count_second++; //adding each second on the time counter
    
  // set cursor to first column, first row
  lcd.setCursor(0, 0);  //set first row for the air quality
  lcd.print("ArQ="); //print message
  lcd.print(sensorValue,DEC);   // print the sensor value into decimal form
  lcd.print(" PPM"); //print PPM
  lcd.setCursor(0, 1); //set cursor to the second column, second row
  lcd.print("Humid="); //print message
  lcd.print(DHT.humidity,DEC);   // print the DHT Humidity into decimal form
  delay(5000);    // Wait 5 seconds
  lcd.clear();   // clears the display to print new message
}
