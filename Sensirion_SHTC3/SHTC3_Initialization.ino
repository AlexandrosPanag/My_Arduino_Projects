/*
 * Created by Alexandros Panagiotakopoulos
*/

#include "Adafruit_SHTC3.h" //original library was made by adafruit

Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

void setup() {
  Serial.begin(115200); //initialize the baud rate

  while (!Serial)
    delay(10);     // wait until the serial port opens

  //check if the sensor was found
  Serial.println("SHTC3 test");
  if (! shtc3.begin()) {
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  }
  Serial.println("Found SHTC3 sensor");
}


void loop() {
  sensors_event_t humidity, temp; 
  shtc3.getEvent(&humidity, &temp);// populate temperature and humidity objects with fresh data
  
  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" °C"); //print the temperature in celsius
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH"); //print the relative humidity
  delay(10000); //delay for 10 seconds
}
