/*
 * Created by Alexandros Panagiotakopoulos
*/

#include "LowPower.h"

// External interrupt on pin 0 (use pin 0 to 24, except pin 4 on Arduino Zero)
const int pin = 0;
unsigned char count = 10; //Declare the arduino counter

void setup()
{
  // Wait for serial USB port to open
  while(!SerialUSB);
  SerialUSB.println("***** Low Power Mode example *****");
  

  // Delay is required to allow the USB interface to be active during
  // sketch upload process
  SerialUSB.println("Entering standby mode in:");
  for (count; count > 0; count--)
  {
    SerialUSB.print(count); 
    SerialUSB.println(" s");
    delay(1000);
  }
  // *********************
    
  // External interrupt on pin (example: press of an active low button)
  // A pullup resistor is used to hold the signal high when no button press
  attachInterrupt(pin, blink, LOW);
}

void loop() 
{
  SerialUSB.println("Entering standby mode.");
  SerialUSB.println("Apply low signal to wake the processor.");
  SerialUSB.println("Zzzz...");
  // Detach USB interface
  USBDevice.detach();
  // Enter standby mode
  LowPower.standby();  
  // Attach USB interface
}

void blink(void) //additional code if we want can be detached here
{

}
