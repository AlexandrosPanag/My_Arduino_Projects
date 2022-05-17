/*********
 By Alexandros Panagiotakopoulos
*********/
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

Adafruit_Sensor *aht_humidity, *aht_temp;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit AHT10/AHT20 test!");

  if (!aht.begin()) { //if the AHT20 Sensor wasn't connected
    Serial.println("Failed to find AHT20 chip"); //print into the serial port the failed
    while (1) { //while the AHT20 sensor wasn't found, 
      delay(10); //delay
    }
  }

  Serial.println("AHT20 Found!");  //if the AHT20 is found
  aht_temp = aht.getTemperatureSensor(); //then get the current temperature
  aht_temp->printSensorDetails(); //print into the serial port the temperature
  aht_humidity = aht.getHumiditySensor(); //get the current humidity
  aht_humidity->printSensorDetails(); //print into the serial port the humidity
}

void loop() {
  Serial.println("*********************************************************************");
  //  /* Get a new normalized sensor event */
  sensors_event_t humidity; //get normalized sensor event the humidity
  sensors_event_t temp;  //get normalized sensor event the temperature
  aht_humidity->getEvent(&humidity); //declare a new variable as the humidity
  aht_temp->getEvent(&temp); //declare a new variable as the temperature

  Serial.print("\t\tTemperature "); //print a message to the serial port
  Serial.print(temp.temperature); //print the temperature
  Serial.println(" deg C");

  /* Display the results (humidity is measured in % relative humidity (% rH) */
  Serial.print("\t\tHumidity: "); //print a 'Humidity' message into the serial port
  Serial.print(humidity.relative_humidity); //print the humidity variable into the serial port
  Serial.println(" % rH"); // print 'relative humidity' message into the serial port
  Serial.print("\t\tTemperature: "); //print 'Temperature' message
  Serial.print(temp.temperature); //print the temperature variable into the serial port
  Serial.println(" degrees °C"); //print 'Degrees in temperatures symbol
  delay(10000); //delay for 10 seconds before taking another temperature
}
