int onoff=0;  //Declaring a check variable on whether or not we pressed the button or we didn't

void setup(){  //Set-up point
  pinMode(GREEN_LED, OUTPUT);   //Declaring the GREEN led as output
  pinMode(PUSH2,INPUT_PULLUP); //Declaring the right button with the input-pullup method
}

void loop() {
  if(digitalRead(PUSH2) == LOW)  //if we pressed the right button
  {
    while(digitalRead(PUSH2) == LOW);  //then keep the led turned off
    onoff++;
}
if(onoff%2 == 0)  //or in case we did NOT press the red button keep the button turned on
{
  digitalWrite(GREEN_LED, HIGH);  //make it turning on for 1/2 second
  delay(500);                   
  digitalWrite(GREEN_LED, LOW);  //make it turning off for 1/2 second
  delay(500);
}
else
{
 digitalWrite(GREEN_LED , LOW); //or keep it off
}
}
