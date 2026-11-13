int onoff=0;  //Declaring a check variable on whether or not we pressed the button or we didn't

void setup(){  //Set-up point
  pinMode(RED_LED, OUTPUT);   //Declaring the red led as output
  pinMode(PUSH1,INPUT_PULLUP); //Declaring the right button with the input-pullup method
}

void loop() {
  if(digitalRead(PUSH1) == LOW)  //if we pressed the right button
  {
    while(digitalRead(PUSH1) == LOW);  //then keep the led turned off
    onoff++;
}
if(onoff%2 == 0)  //or in case we did NOT press the red button keep the button turned on
{
  digitalWrite(RED_LED, HIGH);  //make it turning on for 1/2 second
  delay(500);                   
  digitalWrite(RED_LED, LOW);  //make it turning off for 1/2 second
  delay(500);
}
else
{
 digitalWrite(RED_LED , LOW); //or keep it off
}
}
