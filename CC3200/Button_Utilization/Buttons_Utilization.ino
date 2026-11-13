/*********
 By Alexandros Panagiotakopoulos
*********/
/*
 Based on the original work by DojoDave <http://www.0j0.org>, which is also the File>Examples>Digital>Button, example
 that was already provided
 modified 30 Aug 2011
 by Tom Igoe
 modified Apr 27 2012
 by Robert Wessels
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
//if you want, you can modify one of the LEDs to light YELLOW_LED by adjusting the lines
const int leftButton = PUSH1; //initialize the right button
const int rightButton = PUSH2;     // initialize the left button

// variables will change:
int rightbuttonState = 0;         // variable for reading the pushbutton status
int leftbuttonState = 0;         // variable for reading the pushbutton status
void setup() {
  // initialize the LED pin as an output:
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(rightButton, INPUT_PULLUP); //declare the right button input
  pinMode(leftButton, INPUT_PULLUP); //declare the left button input    
}

void loop(){
  // read the state of the pushbutton value:
  rightbuttonState = digitalRead(rightButton); //declare the right button reading
  leftbuttonState = digitalRead(leftButton); //declare the left button reading
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (rightbuttonState == HIGH) { //if the right button is pressed    
    // turn RED LED on:    
    digitalWrite(RED_LED, HIGH);  
  } 
  else { //if the right button isn't pressed
    // turn RED LED off:
    digitalWrite(RED_LED, LOW); 
  }
  if (leftbuttonState == HIGH) { //if the left button is pressed     
    // turn GREEN LED on:    
    digitalWrite(GREEN_LED, HIGH);  
  } 
  else { //if the left button isn't pressed
    // turn GREEN LED off:
    digitalWrite(GREEN_LED, LOW); 
  }
}
