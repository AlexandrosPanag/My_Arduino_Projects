/*********
 By Alexandros Panagiotakopoulos - alexandrospanag.github.io
*********/

#include <Adafruit_PCT2075.h> //Adafruit PCT2075 by Adafruit

Adafruit_PCT2075 PCT2075; //declare the PCT2075 Object - variable

void setup() {
  PCT2075 = Adafruit_PCT2075(); //initialize the object - variable
  Serial.begin(115200); //begin the serial baud rate to 115200 baud
  // Wait until serial port is opened
  while (!Serial) { delay(1); }
  Serial.println("Adafruit PCT2075 Sensor Test");

  if (!PCT2075.begin()) { //check if the PCT2075 is connected properly or was found
    Serial.println("Couldn't find the PCT2075 sensor"); //if it's not connected properly or wasn't found
    while (1); //stay on the loop
  }  
  Serial.println("Found the PCT2075 sensor"); //otherwise, print that the sensor was found
}

void loop() { //print the serial temperature
  Serial.println("***************************************************");
  Serial.print("Temperature: "); 
  Serial.print(PCT2075.getTemperature());
  Serial.println(" C");
  Serial.println();
  delay(2000);
}
