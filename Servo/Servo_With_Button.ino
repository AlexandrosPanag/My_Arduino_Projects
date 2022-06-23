/*
 * Created by Alexandros Panagiotakopoulos
*/

#include <Servo.h> // original library was based on : https://www.arduino.cc/reference/en/libraries/servo/

Servo servo_1; // servo controller (multiple can exist)

int servo_pin = 4; // PWM pin for servo control
int pos = 0;    // servo starting position

void setup() {
  servo_1.attach(servo_pin); // start servo control
}

void loop() {
  servo_1.write(180);
  
  delay(500);

  servo_1.write(0); //set the servo in the proper position
  delay(500); //delay 15msec
}
