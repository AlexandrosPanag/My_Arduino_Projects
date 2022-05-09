/*********
 By Alexandros Panagiotakopoulos
 this example is based on the book "ARDUINO - Αλγοριθμική, προγραμματισμός και εφαρμογές" by ΑΡΙΣΤΕΙΔΗΣ Σ. ΜΠΟΥΡΑΣ & ΓΙΑΝΝΗΣ Θ. ΚΑΠΠΟΣ, --- page 801
*********/

const byte button = 2; //declare an external button connected to the breadboard


//intial state of the led = blinking
//volatile stands in order to force arduino to transfer the variable into the internal arduino system RAM
volatile byte onoff = true; //blinking onoff variable
volatile byte led_state = HIGH; //state of the led = HIGH

void setup(){
  pinMode(button,INPUT_PULLUP); //declare the button
  pinMode(LED_BUILTIN, OUTPUT); //declare the built-in led as an output

  attachInterrupt(digitalPinToInterrupt(button), isr, FALLING); 
  //intialize the button and the interrupt subroutine
  //falling is the state when high goes to low
  //basically, when we press the button we will intialize a system interrupt
}

void isr(){ //interrupt service routine 
  for(long i = 0; i <10000; i++){ // when the button is pressed
    asm("nop"); //nop stands for NO OPeration
    //delay a clock cycle of 62.b nsec = 1/16 MHz from the 16 clock frequency of the arduino uno
    }
    if(digitalRead(button) == LOW){ //if the button is pressed once
      onoff =!onoff; //stop going on/off = stop blinking
      led_state = true; //
      }
}

void loop(){
  noInterrupts(); //no interrupts stops the interrupts
  digitalWrite(LED_BUILTIN, led_state); 
  if(onoff)led_state =!led_state;
  interrupts(); //interrupts re-enabled them
  delay(250);
}
