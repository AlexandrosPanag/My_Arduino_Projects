/* This code was given during the academic year of september 2021- february 2022 in embedded systems at university of ioannina
- Computer Informatics and Telecommunications */ 

static const uint16_t*ADC15TEMP30 =(uint16_t*)0x1A1A;
static const uint16_t*ADC15TEMP85 =(uint16_t*)0x1A1C;

int temp=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  temp=GetTempX10(3); //temp will return 3-digit number //eg 225->22.5 degrees 
  Serial.println(temp/10);  //divide by 10 to get the real temp
  delay(2000);
}
int16_t GetTempX10(int oversampling)
{
  uint32_t reading=0;
  
  analogReference(INTERNAL1V5); //use the 1.5V internal reference
  
  for(int i=0; i<(1<<oversampling); i++){
    reading+=analogRead(TEMPSENSOR); //do 2^oversampling reads
    delay(2);  //wait 2 ms between successive reads
    }
  reading>>=oversampling; //and divide by 2^oversampling, we are left with the average from 2^oversampling reads.
  
  //Map converts a number from an input range (our calibration constants) to an output range (our temperature)
  return map(reading,*ADC15TEMP30,*ADC15TEMP85,300,850); //convert our reading to temp x 10 & return
} 