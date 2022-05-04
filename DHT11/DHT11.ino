/*
 * Created by Alexandros Panagiotakopoulos
*/

#include "dht.h" 
dht DHT;

void setup(){
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 }//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(2);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity); 
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    if(DHT.temperature >25){
       digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
       delay(1000);                       // wait for a second
       digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
       delay(1000);      
      }
    delay(5000);//Wait 5 seconds before accessing sensor again.
  //Fastest should be once every two seconds.
}// end loop() 
