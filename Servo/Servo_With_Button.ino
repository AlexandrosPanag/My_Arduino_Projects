/*
 * Created by Alexandros Panagiotakopoulos
*/

#include <Servo.h>

Servo servo_1; // servo controller (multiple can exist)

int servo_pin = 2; // PWM pin for servo control
int pos = 0;    // servo starting position

void setup() {
  servo_1.attach(servo_pin); // start servo control
}

void loop() {
  int positioning; //declare the positioning as an integer value

  servo_1.write(180); //write the servo into 180 degrees spin
  delay(5000); //delay 5 seconds
  servo_1.write(0); //write the servo into 0 degrees (the original position)
  delay(5000); //delay 5 seconds

  
  //get to the position of 180 degrees
  for(positioning = 0; positioning <= 180; positioning +=5){
    servo_1.write(positioning); //write the current position of the servo 
    delay(500); //delay half a second
    }
    for( positioning = 180; positioning >= 0; positioning -=5) //do the exact opposite get from the position 180 to 0 degrees
    {
      servo_1.write(positioning);
      delay(500); //delay half a second
      }
}
