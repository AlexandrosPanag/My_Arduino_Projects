/*********
 By Alexandros Panagiotakopoulos
 this example is based on the book "ARDUINO - Αλγοριθμική, προγραμματισμός και εφαρμογές" by ΑΡΙΣΤΕΙΔΗΣ Σ. ΜΠΟΥΡΑΣ & ΓΙΑΝΝΗΣ Θ. ΚΑΠΠΟΣ, --- page 794
*********/

#include <msTask.h> //library by maisonmd
// we also need the library TimerOne.h by Paul Stoffregen

int foo_count = 0; //create a foo_counter
int bar_count = 0; //create a bar counter


void foo(){ //count the foo() function and increase the value every time it is called
  Serial.println("Foo has run(). times:" +String (++foo_count)); //print into the serial port the times
  //the function was called
}


void bar(){ //count the bar() function and increase the value every time it is called
  Serial.println("Bar has run(). times:" +String (++bar_count)); //print into the serial port the times
  //the function was called
}

msTask fooTask(1700,foo); //delay for 1,7 seconds
msTask barTask(2300,bar); //delay for 2,3 seconds

 //Declaring the buzzer as an output
void setup() {
   Serial.begin(115200); //initialize the serial baud rate to 115200
   pinMode(LED_BUILTIN, OUTPUT); //declare the led as an output
   msTask::init(); //intialize the mstask library -- in order to start the counter
}
byte val = LOW;

void loop() {
digitalWrite(LED_BUILTIN, val);
val=!val;
}
