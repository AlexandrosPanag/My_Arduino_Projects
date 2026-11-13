int ledState = LOW;             // Declaring the state of both our leds
long previousMillis = 0;        // will store last time LED was updated


long interval = 500;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pins as outputs:
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop()
{ 
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(GREEN_LED, ledState);
    digitalWrite(RED_LED,ledState);
  }
}