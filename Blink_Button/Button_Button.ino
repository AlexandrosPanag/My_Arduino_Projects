/*
 * Created by Alexandros Panagiotakopoulos
*/


const int buttonPin = 2;     // the number of the pushbutton pin
int onoff=0;                 //Declaring a button state

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (digitalRead(buttonPin) == LOW) {
    while(digitalRead(buttonPin) == LOW){
    onoff++;
    }
    // wait for a second
  }
  if(onoff%2==0)
  {
    // turn LED off:
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a half-second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(500);                        //wait for a half-second
  }
}

  
