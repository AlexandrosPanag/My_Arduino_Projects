void setup() {                
  Serial.begin(9600);    
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  if(Serial.available())
  {
    int x=Serial.parseInt();
    Serial.println(x);
    if(x==1){  //if the user types "1"
      digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)      
      }
      else if(x==2) //"if the user types "2"
      {
        digitalWrite(RED_LED, LOW);       
      }
      else if(x==3) //if the user types "3" 
      {
      digitalWrite(GREEN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)     
      }
      else if(x==4) //if the user types "4"
      {
        digitalWrite(GREEN_LED, LOW);
      }
    }
}