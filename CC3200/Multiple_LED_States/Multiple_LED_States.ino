/*********
 By Alexandros Panagiotakopoulos
*********/

int counter = 0;
int red_counter=0;
int green_counter=0;
int yellow_counter=0;


void setup() {
  Serial.begin(9600); //Initialize the baud rate to 9600 bauds/sec
  // set the boards led to output
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  if(counter%2==0){ //if the counter modulo 2 == 0, RED and GREEN, will turn on while YELLOW, will remain off
    Serial.println("**Counter is equal to 0, GREEN and RED will light**");
     
    digitalWrite(RED_LED, HIGH);   // turn the RED LED on (HIGH is the voltage level)
    red_counter=1;
    
    digitalWrite(GREEN_LED, HIGH);   // turn the GREEN LED on (HIGH is the voltage level)
    green_counter=1;
    
    digitalWrite(YELLOW_LED, LOW);   // turn the YELLOW LED off (HIGH is the voltage level)
    yellow_counter=0;
    
    delay(5000);      // wait for about 5 seconds, then RED and GREEN will remain off, while YELLOW will turn on.  
    
    Serial.println("**Counter is equal to 0, the yellow will light**");  

    digitalWrite(RED_LED, LOW );    // turn the RED LED off by making the voltage LOW
    yellow_counter=0;
    
    digitalWrite(GREEN_LED, LOW);   // turn the GREEN LED off (HIGH is the voltage level)
    green_counter=0;
    
    digitalWrite(YELLOW_LED, HIGH);   // turn the YELLOW LED on (HIGH is the voltage level)
    yellow_counter=1;
    
    delay(5000); // wait for about 5 seconds

  Serial.println();
  }
  else{ //if the counter modulo 2 == 1, RED remain off, while GREEN and YELLOW will turn on.
    Serial.println("**Counter is equal to 1, GREEN and YELLOW will light**"); 
    
    digitalWrite(RED_LED, LOW);   // turn the RED LED off (HIGH is the voltage level)
    red_counter=0;
    
    digitalWrite(GREEN_LED, HIGH);   // turn the GREEN LED on (HIGH is the voltage level)
    green_counter=1;
    
    digitalWrite(YELLOW_LED, HIGH);   // turn the YELLOW LED on (HIGH is the voltage level)
    yellow_counter=1;
    
    delay(5000);      // wait for about 5 seconds then RED will turn on while GREEN and YELLOW will turn off

    Serial.println("**Counter is equal to 1, RED will light**"); 
    
    digitalWrite(RED_LED, HIGH);    // turn the RED LED off by making the voltage LOW
    red_counter=1;
    
    digitalWrite(GREEN_LED, LOW);   // turn the GREEN LED on (HIGH is the voltage level)
    green_counter=0;
    
    digitalWrite(YELLOW_LED, LOW);   // turn the YELLOW LED on (HIGH is the voltage level)
    yellow_counter=0;
    
    delay(5000);      // wait for about 5 seconds, 
  }
  counter++;
}
