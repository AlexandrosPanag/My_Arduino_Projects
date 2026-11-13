int time_count_second=0; //DECLARING A GLOBAL COUNTER VARIABLE

void setup()  //SET-UP-POINT
{
  Serial.begin(9600);  //DECLARING THE BAUD RATE
  pinMode(RED_LED, OUTPUT); //DECLARING THE RED LED AS AN OUTPUT
  pinMode(GREEN_LED, OUTPUT); //DECLARING THE GREEN LED AS AN OUTPUT   
}
void loop() //INFINITE LOOP POINT
{
  time_count_second++; //ADDING WITH EACH SECOND TIME = TIME +1
  Serial.println(time_count_second);  //PRINTING THE TIME ELAPSED 
  
  if(time_count_second%2 == 0){  //IF THE TIME IS 2 , 4 , 6 , 8 THE RED ONLY MUST BLINK -- THE GREEN MUST BE OFF
    digitalWrite(RED_LED,HIGH); //LIGHT ONLY THE RED
    delay(100); //DELAY 0.1 SECOND
    digitalWrite(GREEN_LED,LOW); //LIGHT OFF THE GREEN LED
    delay(100); //DELAY 0.1 SECOND
    }
    else{ //IF THE TIME IS 1 ,3 ,5 ,7 ,9 LIGHT ONLY THE GREEN LED
      digitalWrite(GREEN_LED,HIGH); //WRITE THE GREEN LED HIGH
      delay(100); //DELAY 0.1 SECOND
      digitalWrite(RED_LED,LOW); //LIGHT OFF THE RED LED
      delay(100); //DELAY 0.1 SECOND
      }
  delay(800); //ADDING ONE SECOND AS A TIMER
}