
/* A simple program to sequentially turn on and turn off 3 LEDs */ 

int RED_LED = 13; //initialize the arduino pin _number 13
int YELLOW_LED = 12; //initialize the arduino pin_number 12
int GREEN_LED = 11; //initialize the arduino pin_number 11

void setup() {
   pinMode(RED_LED, OUTPUT); //set the red_led as an output
   pinMode(YELLOW_LED, OUTPUT); //set the yellow_led as an output
   pinMode(GREEN_LED, OUTPUT); //set the green_led as an output
}


void loop() {
  digitalWrite(RED_LED, HIGH);    // turn on RED_LED 
  delay(500);                  // wait for half a second
  digitalWrite(YELLOW_LED, HIGH);    // turn on YELLOW_LED 
  delay(500);                  // wait for half a second
  digitalWrite(GREEN_LED, HIGH);    // turn on GREEN_LED 
  delay(500);                  // wait for half a second
  digitalWrite(RED_LED, LOW);    // turn OFF RED_LED 
  delay(500);                  // wait for half a second
  digitalWrite(YELLOW_LED, LOW);    // turn OFF YELLOW_LED  
  delay(500);                  // wait for half a second
  digitalWrite(GREEN_LED, LOW);    // turn OFF YELLOW_LED 
  delay(500);                  // wait for half a second
}
