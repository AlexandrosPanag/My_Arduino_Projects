/****************************************************************
Original library documentation can be found here : https://github.com/Depau/APDS9930
Another useful documentation can be found here : https://electropeak.com/learn/interfacing-apds-9930-proximity-and-ambient-light-and-gesture-sensor-with-arduino/
Connect as following with your sensor: 
VCC: Module power supply – 2.4 – 3.6 V
GND: Ground
SDA: I2C data signal
SCL: I2C clock signal

/*********
 By Alexandros Panagiotakopoulos
*********/


#define PWM_LED_PIN       10
#define DUMP_REGS

#include <Wire.h>
#include <APDS9930.h>

// Global Variables
APDS9930 apds = APDS9930(); //declare the APDS 9930 library as an object
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0; 
uint16_t ch1 = 1;
float max_light = 0; //declare a maximum lighting
float max_ambient = 400;
void setup() {
  //analogReference(EXTERNAL);
  pinMode(PWM_LED_PIN, OUTPUT);
  
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("APDS-9930 - Ambient light sensor"));
  Serial.println(F("--------------------------------"));
  
  // Initialize APDS-9930 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9930 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }
  
  // Start running the APDS-9930 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

#ifdef DUMP_REGS
  /* Declare the necessary register values */
  uint8_t reg;
  uint8_t val;

  for(reg = 0x00; reg <= 0x19; reg++) {
    if( (reg != 0x10) && \
        (reg != 0x11) )
    {
      apds.wireReadDataByte(reg, val);
      Serial.print(reg, HEX);
      Serial.print(": 0x");
      Serial.println(val, HEX);
    }
  }
  apds.wireReadDataByte(0x1E, val);
  Serial.print(0x1E, HEX);
  Serial.print(": 0x");
  Serial.println(val, HEX);
#endif

  // Wait for initialization and calibration to finish
  delay(500);
}

void loop() {
  
  // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLightLux(ambient_light) ||
        !apds.readCh0Light(ch0) || 
        !apds.readCh1Light(ch1) ) {
    Serial.println(F("Error reading light values"));
  } else {
    Serial.print(F("Ambient: "));
    Serial.print(ambient_light);
    Serial.print(F("  Ch0: "));
    Serial.print(ch0);
    Serial.print(F("  Ch1: "));
    Serial.println(ch1);

    //if ambient light is bigger than 400 then blink the board
    if ( max_ambient > ambient_light ) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000); 
    }
    else{ //don't blink
    }
    ambient_light = map(ambient_light, 0, max_light, 0, 1023);
    analogWrite(PWM_LED_PIN, ambient_light);
  }
  
  // Wait 1 second before next reading
  delay(1000);
}
