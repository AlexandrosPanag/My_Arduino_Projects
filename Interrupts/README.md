Interrupts
------------------------------

What are interrupts?

Interrupt is a signal emitted by hardware or software when a process or an event  needs immediate attention. It alerts the processor to a high priority  process requiring interruption of the current working process. In I/O  devices one of the bus control lines is dedicated for this purpose and  is called the Interrupt Service Routine (ISR).

SOURCE : https://create.arduino.cc/projecthub/rafitc/interrupts-basics-f475d5



Interrupt Service Routine
----------

In this project, i declare two functions the void foo() function and the void bar() function and delay each function seperately for 1,7 (foo()) seconds and 2,3 (bar()) seconds each, every time the functions are called i increase each seperate counter by 1 , and print on the serial port the number each function was called (using the counters that i declared) 
