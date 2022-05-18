/*********
 By Alexandros Panagiotakopoulos
*********/

#include <Wire.h>
#include "Adafruit_HTU21DF.h"

Adafruit_HTU21DF htu = Adafruit_HTU21DF();

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D-F test");

  if (!htu.begin()) { //check if the sensor is connected properly or was found
    Serial.println("Couldn't find sensor!"); //if the sensor was not found print the appropriate message
    while (1);
  }
}

void loop() {
    Serial.println("****************************************** ");
    float temp = htu.readTemperature(); //read the temperature
    float r_h = htu.readHumidity(); //read the relative humidity

    //print the temperature
    Serial.print("Temperature: "); 
    Serial.print(temp); 
    Serial.print(" °C");

    //print the relative humidity
    Serial.print("Humidity: "); 
    Serial.print(r_h); 
    Serial.println(" \%");
    
    delay(10000); //delay for 10 seconds
}
