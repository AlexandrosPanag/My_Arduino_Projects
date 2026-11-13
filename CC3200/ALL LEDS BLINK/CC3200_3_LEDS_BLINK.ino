/*********
 By Alexandros Panagiotakopoulos
*********/

void setup() {
  // set the boards led to output
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  digitalWrite(RED_LED, HIGH);   // turn the RED LED on (HIGH is the voltage level)
  digitalWrite(GREEN_LED, HIGH);   // turn the GREEN LED on (HIGH is the voltage level)
  digitalWrite(YELLOW_LED, HIGH);   // turn the YELLOW LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the RED LED off by making the voltage LOW
  digitalWrite(GREEN_LED, LOW);   // turn the GREEN LED on (HIGH is the voltage level)
  digitalWrite(YELLOW_LED, LOW);   // turn the YELLOW LED on (HIGH is the voltage level)
  delay(1000); // wait for a second
}
