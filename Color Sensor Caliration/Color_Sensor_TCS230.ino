/*

 Color sensor calibration project by ALEXANDROS PANAGIOTAKOPOULOS

 The TCS239 operates on a wide voltage rate and outputs square wave whose frequency reflects the color intensity
 Signal output
The signal output by the TCS230 is obtained by a current to frequency converter that takes as its input the average current from the selected set of photodiodes. 
The idea is that you switch one set on, take a reading and then switch to the next set until all four measurements are done. 
The output signal is a square wave with even mark to space ratio: 50% high, 50% low.
SOURCE: https://www.best-microcontroller-projects.com/tcs230.html


 Meterial used : Arduino UNO
                 TCS230
*/




#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

//variables for color pulse width measurements

int red_pulse = 0;
int green_pulse = 0;
int blue_pulse =  0;



  /// VOID SETUP ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {


  //Setting up S0, S1, S2 , S3  AS OUTPUTS
 pinMode(S0, OUTPUT);
 pinMode(S1, OUTPUT);
 pinMode(S2, OUTPUT);
 pinMode(S3, OUTPUT);

 // Set sensor output as input
 pinMode(sensorOut, INPUT);

 // Set pulse width scaling to 20%
 digitalWrite(S0, HIGH);
 digitalWrite(S1, LOW);

 //Setup Serial Monitor
 Serial.begin(9600);
}

  /// VOID LOOP //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void loop(){

    // read red pulse width
    red_pulse = getRedPulse();
    // Delay to stabilize sensor
    delay(200);

    // Read green pulse width
    green_pulse = getGreenPulse();
    // Delay to stabilize sensor
    delay(200);

    // read blue pulse width
    blue_pulse = getBluePulse();
    // Delay to stabilize sensor
    delay(200);
      
      

 

   // Print output to serial monitor
   Serial.print ("Red pulse = ");
   Serial.print(red_pulse);
   Serial.print ("\n");
   Serial.print("Green pulse = ");
   Serial.print(green_pulse);
   Serial.print ("\n");
   Serial.print("Blue pulse = ");
   Serial.print(blue_pulse);
   Serial.print ("\n");
  }

  int getRedPulse(){
    //SET SENSOR TO READ RED ONLY
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Define integer to represent Pulse width
    int PW;
    // Read the output pulse width
    PW = pulseIn(sensorOut, LOW);
    //return pulse width;
    return PW;
  }

    int getGreenPulse(){
    //SET SENSOR TO READ GREEN ONLY
    digitalWrite(S2,HIGH);
    digitalWrite(S3,HIGH);
    // Define integer to represent Pulse width
    int PW;
    // Read the output pulse width
    PW = pulseIn(sensorOut, LOW);
    //return pulse width;
    return PW;
  }

    int getBluePulse(){
    //SET SENSOR TO READ BLUE ONLY
    digitalWrite(S2,LOW);
    digitalWrite(S3,HIGH);
    // Define integer to represent Pulse width
    int PW;
    // Read the output pulse width
    PW = pulseIn(sensorOut, LOW);
    //return pulse width;
    return PW;
  }
