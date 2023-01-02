/*********
 By Alexandros Panagiotakopoulos - alexandrospanag.github.io
 Built-in blink LED - Works on Arduino Uno Rev 3, Arduino Nano 33 IoT, Arduino Nano among many other boards.
*********/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for two seconds
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for two seconds
}
