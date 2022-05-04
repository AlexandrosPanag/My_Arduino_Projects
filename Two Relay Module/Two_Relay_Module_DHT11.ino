/*
 * Created by Alexandros Panagiotakopoulos
*/


#include "dht.h" 
dht DHT;
int RelayPinOne = 12;
int RelayPinTwo = 11;

void setup() {
	Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
	// Set RelayPin as an output pin
	pinMode(RelayPinOne, OUTPUT);
	pinMode(RelayPinTwo, OUTPUT);
}

void loop() {
    DHT.read11(2);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity); 
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
	// Let's turn on the relay...
 if(DHT.temperature >25){
	digitalWrite(RelayPinOne, HIGH);
	delay(3000);
	digitalWrite(RelayPinTwo, HIGH);
	delay(3000);
 }
 else
 {
	// Let's turn off the relay...
	digitalWrite(RelayPinOne, LOW);
	delay(3000);
	digitalWrite(RelayPinTwo, LOW);
	delay(3000);
}
