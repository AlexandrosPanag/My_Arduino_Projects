/*********
 By Alexandros Panagiotakopoulos
 this example is based on the book " ARDUINO ΑΛΓΟΡΙΘΜΙΚΗ , ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ ΚΑΙ ΕΦΑΡΜΟΓΕΣ " by ΑΡΙΣΤΕΙΔΗΣ Σ. ΜΠΟΥΡΑΣ & ΓΙΑΝΝΗΣ Θ. ΚΑΠΠΟΣ - page 782  
*********/

#include <HCSR04.h> //include the library from Martin Sosic

const int TRIGGER = 13; //initialize the trigger sensor in pin D13
const int ECHO = 12; //intialize the echo sensor in pin D12

UltraSonicDistanceSensor ultrasound(TRIGGER, ECHO); //intialize the trigger and echo sensors

void setup(){
  Serial.begin(115200); //begin the baud rate 115200
}

void loop(){
  float distance = ultrasound.measureDistanceCm(); //return the distance from the class measureDistanceCm
  Serial.println("The distance is: "+String(distance)+" cm"); //print the distance into the serial port
  delay(1000); //delay 1 second
}
