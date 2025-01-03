// Created By Alexandros Panagiotakopoulos - alexandrospanag.github.io                                             
// DATE: 29/07/2024   
int value; //save analog value


void setup(){
  pinMode(A2, INPUT); //LED Pin 
  Serial.begin(9600); //Initialize Serial Monitior (OPTIONAL) to check the values.
}

void loop(){
  value = analogRead(A2);          //Read and save analog value from potentiometer
  value = map(value, 0, 1023, 0, 255); //Map value 0-1023 to 0-255 (PWM)
  analogWrite(9, value);          //Send PWM value to led
  delay(100);                          //Small delay
  Serial.println(value); //Check the volume 0 through the Serial 0 for OFF (minimum lighting volume), 255 for ON (maximum lighting volume) 
}
