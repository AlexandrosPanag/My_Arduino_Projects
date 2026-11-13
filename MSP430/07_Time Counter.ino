int time_count_second=0; //DECLARING A GLOBAL COUNTER VARIABLE

void setup()  //SET-UP-POINT
{
  Serial.begin(9600);  //DECLARING THE BAUD RATE
}
void loop() //INFINITE LOOP POINT
{
  time_count_second++; //ADDING WITH EACH SECOND TIME = TIME +1
  Serial.println(time_count_second);  //PRINTING THE TIME ELAPSED 
  delay(1000); //ADDING ONE SECOND AS A TIMER
}