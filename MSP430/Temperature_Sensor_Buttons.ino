static const uint16_t*ADC15TEMP30 =(uint16_t*)0x1A1A;
static const uint16_t*ADC15TEMP85 =(uint16_t*)0x1A1C;


int rightpressed=0; //Declaring a variable for the times right button was pressed
int leftpressed=0; //Declaring a variable

  
void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);   //Declaring the red led as output
  pinMode(PUSH1,INPUT_PULLUP); //Declaring the right button with the input-pullup method
  pinMode(GREEN_LED, OUTPUT);   //Declaring the GREEN led as output
  pinMode(PUSH2,INPUT_PULLUP); //Declaring the right button with the input-pullup method
  Serial.begin(9600); //initialize monitor 9600 baud per sec
}


void loop() {
  int temp=GetTempX10(3); //temp will return 3-digit number //eg 225->22.5 degrees 
  // put your main code here, to run repeatedly: 
  delay(1000); //delay 10 seconds before each temperature print

  
if(digitalRead(PUSH1) == LOW)  //if we pressed the right button
  {
    while(digitalRead(PUSH1) == LOW);  //then keep the times the right button was pressed
    rightpressed++;
    leftpressed--;
}


if(digitalRead(PUSH2) == LOW)  //if we pressed the left button
  {
    while(digitalRead(PUSH2) == LOW);  //then count the times the left button was pressed
    leftpressed++;
    rightpressed--;
}

if(rightpressed%2 == 0 || leftpressed<=-1)  //or in case we did NOT press the red button keep the button turned on
{
  digitalWrite(GREEN_LED, HIGH);  //make it turning on for 1/2 second
  delay(500);    
  digitalWrite(RED_LED, LOW);  //make it turning on for 1/2 second
  delay(500);                  
}
else
{ 
 digitalWrite(RED_LED , HIGH); //or keep it off
 delay(500);
 digitalWrite(GREEN_LED, LOW);  //make it turning on for 1/2 second
 delay(500);
}

if(leftpressed%2 == 0|| rightpressed<=-1)  //or in case we did NOT press the red button keep the button turned on
{
  digitalWrite(GREEN_LED, HIGH);  //make it turning on for 1/2 second
  delay(500); 
  digitalWrite(RED_LED, LOW);  //make it turning on for 1/2 second
  delay(500);                  
}
else
{
 digitalWrite(RED_LED , HIGH); //or keep it off
 delay(500);
 digitalWrite(GREEN_LED, LOW);  //make it turning on for 1/2 second
 delay(500);
}

  Serial.write("Temperature is °C : ");
  int truetemp=temp/10; //divide by 10 to get the real temp
  Serial.println(truetemp+rightpressed+leftpressed);  //add or sub according to the buttons we pressed
}

int16_t GetTempX10(int oversampling)
{
  uint32_t reading=0;
  
  analogReference(INTERNAL1V5); //use the 1.5V internal reference
  
  for(int i=0; i<(1<<oversampling); i++){
    reading+=analogRead(TEMPSENSOR); //do 2^oversampling reads
    delay(2);  //wait about 2ms
    }
  reading>>=oversampling; //and divide by 2^oversampling, we are left with the average from 2^oversampling reads.
  
  //Map converts a number from an input range (our calibration constants) to an output range (our temperature)
  return map(reading,*ADC15TEMP30,*ADC15TEMP85,300,850); //convert our reading to temp x 10 & return
} 
