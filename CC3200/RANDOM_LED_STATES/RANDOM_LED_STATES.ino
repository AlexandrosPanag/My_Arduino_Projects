/*********
 By Alexandros Panagiotakopoulos
 for an enchanced documentation on what random does i encourage you to look at : https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
*********/

void setup() {
  // set the boards led to output
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  Serial.begin(9600); //initialize the Serial port to 9600 bauds/sec
  randomSeed(analogRead(0));// if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
}

void loop() {
  Serial.println();
  Serial.println("**********************************");
  // generate a random number from 10 to 19, then store them to each counter that represents an LED
  int randRed = random(10, 20);
  int randGreen = random(10, 20);
  int randYellow = random(10,20);

  if(randRed%2==0){ //if the red random number can be modulated
    Serial.println("RED WILL TURN ON");
    digitalWrite(RED_LED, HIGH);   // turn the RED LED on (HIGH is the voltage level)
    delay(1000); //wait for about 1 second 
  }
  else{ //if the red random number can't be modulated
    Serial.println("RED WILL TURN OFF");
    digitalWrite(RED_LED, LOW);   // turn the RED LED on (HIGH is the voltage level)
    delay(1000); //wait for about 1 second 
  }

  
  if(randGreen%2==0){ //if the green random number can be modulated
    Serial.println("GREEN WILL TURN ON");
    digitalWrite(GREEN_LED, HIGH);   // turn the RED LED on (HIGH is the voltage level)
    delay(1000); //wait for about 1 second 
  }
  else{ //if the green random number can't be modulated
    Serial.println("GREEN WILL TURN OFF");
    digitalWrite(GREEN_LED, LOW);   // turn the RED LED on (HIGH is the voltage level)
    delay(1000); //wait for about 1 second 
  }

  
  if(randYellow%2==0){ //if the yellow random number can be modulated
    Serial.println("YELLOW WILL TURN ON");
    digitalWrite(YELLOW_LED, HIGH);   // turn the RED LED on (HIGH is the voltage level)
    delay(1000); //wait for about 1 second 
  }
  else{
    Serial.println("GREEN WILL TURN OFF"); ////if the yellow random number can be modulated
    digitalWrite(YELLOW_LED, LOW);   // turn the RED LED on (HIGH is the voltage level)
    delay(1000); //wait for about 1 second 
  }

  
  Serial.println("***********************************");
  delay(5000); // wait for 5 seconds
}
