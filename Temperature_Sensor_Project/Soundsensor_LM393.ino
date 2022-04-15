int soundSensor=1; //declaring the sound sensor value
int LEDfirst=4;  //declaring the first LED pin
int LEDsecond=6; //declaring the second LED pin
boolean LEDStatus=false; 
boolean LEDStatuss=true;

void setup() { //declaring the necessary inputs
 pinMode(soundSensor,INPUT); 
 pinMode(LEDfirst,OUTPUT);
 pinMode(LEDsecond,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  int SensorData=digitalRead(soundSensor); //reading from the sensor
    Serial.print(SensorData);
  if(SensorData==1){

    // basic code -- the light will light if there is sound
    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LEDfirst,HIGH);
        delay(1000);
    }
    else{
        LEDStatus=false;
        digitalWrite(LEDfirst,LOW);
    }
    // Reverse code -- the light will light if there is total silence
        if(LEDStatuss==true){
         LEDStatus=false;
        digitalWrite(LEDsecond,LOW);
        delay(1000);
    }
    else{
        LEDStatuss=true;
        digitalWrite(LEDsecond, HIGH);
    }
  }
 } 
