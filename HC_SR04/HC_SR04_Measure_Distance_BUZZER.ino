/*********
 By Alexandros Panagiotakopoulos.
 
 Besides the HC_SR04 this program is using a Buzzer and an LED light (optional) 
 this example is based on the book " ARDUINO ΑΛΓΟΡΙΘΜΙΚΗ , ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ ΚΑΙ ΕΦΑΡΜΟΓΕΣ " by ΑΡΙΣΤΕΙΔΗΣ Σ. ΜΠΟΥΡΑΣ & ΓΙΑΝΝΗΣ Θ. ΚΑΠΠΟΣ - page 784  
*********/

#include <HCSR04.h> //include the library from Martin Sosic

const byte TRIGGER = 13;  //initialize the trigger sensor in pin D13
const byte ECHO = 12; //intialize the echo sensor in pin D12
const byte BUZZER = 2; //initialize the buzzer in D2

//declare the Steinhart - hart equation fomula

const float R1 = 10000;
const float A = 1.001924950e-03;
const float B = 1.785378405e-04;
const float C = 2.0192022697e-07;

UltraSonicDistanceSensor ultrasound(TRIGGER , ECHO); //declare an object (basically the HC_SR04 sensor) named "ultrasound"

float thermCelsius(){ // we turn the environment objects into temperature in celsius
  
  float r2, t, tc;

  //reading the voltage output
  int vo = analogRead(A0);

  //calculating the R2 value
  r2 = R1 * (1023.0 / float(vo) - 1.0);

  //calculating the value of the Steinhart - hart equation
  //for more info check : https://www.skyeinstruments.com/wp-content/uploads/Steinhart-Hart-Eqn-for-10k-Thermistors.pdf
  // basically we translate electricity / sensor values into Kelvin
  //the temperature will be translated to Kelvin

  t = 1.0/ (A + B* log(r2) + C * pow(log(r2),3));

  //return the temperature to Celsius instead of Kelvin
  return t - 273.15;
  }

 //Declaring the buzzer as an output
void setup() {
  pinMode(BUZZER, OUTPUT); //declare the buzzer as an output
   Serial.begin(115200); //begin the baud rate 115200
}

void loop() {
 //if the HC_SR04 sensor finds an object/ wall in the near distance the BUZZER will beep constantly, if not the buzzer will beep according to the distance
  float distance = ultrasound.measureDistanceCm(thermCelsius());
  Serial.println("The distance is: "+String(distance)+" cm"); //print the distance into the serial port 
  tone(BUZZER, 1000);

  if(distance != -1){ 
    delay(100);
    noTone(BUZZER);
    delay(distance*3);
    }
}
