Interrupts
------------------------------

What are interrupts?

Interrupt is a signal emitted by hardware or software when a process or an event  needs immediate attention. It alerts the processor to a high priority  process requiring interruption of the current working process. In I/O  devices one of the bus control lines is dedicated for this purpose and  is called the Interrupt Service Routine (ISR).

SOURCE : https://create.arduino.cc/projecthub/rafitc/interrupts-basics-f475d5

Interrupt is a mechanism in which an event forces the microprocessor to temporarily stop (interrupt) the main program flow and give priority into running a routine (interrupt service routine) (this was an unofficial translation from greek to english made by me)

SOURCE : ARDUINO "ΑΛΓΟΡΙΘΜΙΚΗ, ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ ΚΑΙ ΕΦΑΡΜΟΓΕΣ" page 799


Interrupt Service Routine
----------

In this project, i declare two functions the void foo() function and the void bar() function and delay each function seperately for 1,7 (foo()) seconds and 2,3 (bar()) seconds each, every time the functions are called i increase each seperate counter by 1 , and print on the serial port the number each function was called (using the counters that i declared) 


Interrupt Service Routine Stop The Process Button
----------

Using a button and connecting it with an arduino Uno (it was run on rev 3 but it can also be run on any version you may own -- can also be done using an esp8266 etc), in this project, i use a button connected to breadboard in order to create an interrupt service routine. Basically, when the button from the breadboard is pressed once, we cause an interrupt and prevent the arduino built-in led from blinking, when we press the button again, we make the built in led to blink again. 
