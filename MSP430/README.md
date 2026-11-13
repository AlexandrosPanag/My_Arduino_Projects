# Ti-launch-pad-with-MSP430-MCU 
----------




My MSP430F5529 archive, this LaunchPad was provided during the academic year 2020-2021 & 2021-2022 during the lessons Microprocessor Systems & Embedded Systems!
![](https://energia.nu/pinmaps/img/LaunchPadMSP430G2452-v1.5.jpg)

----------
GR:
----------

Ο κώδικας μπορεί να μεταγλωττιστεί στο πρόγραμμα energia.

Energia:https://energia.nu/download/

Σας προτείνω να δείτε τα αρχεία μου που περιέχουν Arduino & ESP προγράμματα, τα οποία ανανεώνονται και λαμβάνουν υποστήριξη και αλλαγές πιο συχνά:
https://github.com/AlexandrosPanag/My_Arduino_Projects, https://github.com/AlexandrosPanag/My_esp8266_Projects, https://github.com/AlexandrosPanag/My_ESP32_Projects


Driver software for energia:http://processors.wiki.ti.com/index.php/MSP_Debug_Stack#Windows

----------
EN:
----------

My archieve on the programming language for the microprocessor MSP430F5529!
The code can be compiled on the Energia program

I highly encourage you to check out my Arduino & ESP Archive programs which are constantly updated and receive support & updates more frequently:
https://github.com/AlexandrosPanag/My_Arduino_Projects, https://github.com/AlexandrosPanag/My_esp8266_Projects, https://github.com/AlexandrosPanag/My_ESP32_Projects

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 01_Blink
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου μπορούμε να επηρεάσουμε τον χρόνο που ανάβει και σβήνει το κόκκινο led φώς.


EN: A program that we have the ability to affect the time that our red led lights on and off.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 02_Blink (green)
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου μπορούμε να επηρεάσουμε τον χρόνο που ανάβει και σβήνει το πράσινο led φώς.


EN: A program that we have the ability to affect the time that our green led light on and off.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 03_BLINK - GREEN AND LED.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου μπορούμε να επηρεάσουμε τον χρόνο που ανάβει και σβήνει το κόκκινο led και πράσινο led φώς.



EN: A program that we have the ability to affect the time which our red led and green led light on and off.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 04_Blink using millis.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου μπορούμε μπορούμε να κάνουμε τα led φώτα στη πλακέτα να αναβοσβήνουν χωρίς delay() χρησιμοποιώντας τη millis()



EN: A program that we can affect our led lights by turning them on and off without using the delay() function and using the millis() instead

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 05_Blink with button - RED .ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου υπο κανονική λειτουργία το πρόγραμμα μας θα λειτουργεί με αναβοσβήσιμο του κόκκινου led για διάρκεια 1 second και αν πατήσουμε για μια φορά το δεξιό κουμπί το
led μας θα σβήνει.


EN: A program that makes the right button usable. The program under normal condition works with making the light blink however, when we press the right button the led must turn off. 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 06_Recognise numbers and blink accordingly.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου έχει τη δυνατότητα να διαβάζει 4 input απο τον χρήστη και εκτελεί μια απο τις ακόλουθες 4 διαδικασίες
1- Το ΚΟΚΚΙΝΟ led θα ανάβει
2- Το ΚΟΚΚΙΝΟ led θα σβήνει
3- Το ΠΡΑΣΙΝΟ led θα ανάβει
4- το ΠΡΑΣΙΝΟ led θα σβήνει

EN: A program that gives the abillity for our msp board to recognise four inputs and give one of the four values accordingly:
1- the RED led will light
2- the RED led will turn off
3- the Green light will light
4- the green light will turn off


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 07_Time_Counter.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου έχει τη δυνατότητα να μετράει τον πραγματικό χρόνο σε second ξεκινώντας απο το 1 σαν χρονόμετρο

EN: A program that has the abillity to count each passing second like a time counter

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - 08_Time_Counter with Blinking.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου έχει τη δυνατότητα να μετράει τον πραγματικό χρόνο σε second ξεκινώντας απο το 1 σαν χρονόμετρο και κάθε 1,3,5,7,9 δευτερόλεπτα (time mod 2 = 0 ) θα ανάβει το πράσινο LED αλλιώς θα ανάβει το κόκκινο.

EN: A program that has the abillity to count each passing second like a time counter and every 1 , 3, 5 ,7 ,9 seconds (time mod 2 = 0) the green LED will light otherwise only the red led will light

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - Temperature Sensor.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου ενεργοποιεί τον εσωτερικό αισθητήρα του MSP430 για να δείξει τη θερμοκρασία. Ο κώδικας δόθηκε το ακαδημαϊκό έτος 2021-2022 στο μάθημα Ενσωματωμένων Συστημάτων Εργαστήριο στο 7ο εξάμηνο.

EN: A program that can activate the internal thermal sensor of the MSP430 to show us the temperature. This code was given during the academic year of 2021-2022 in the lesson of Embedded Systems Lab in the 7th Semester.


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
MSP430 - Temperature Sensor Buttons.ino
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
GR: Πρόγραμμα όπου ενεργοποιεί τον εσωτερικό αισθητήρα του MSP430 για να δείξει τη θερμοκρασία και με τη χρήση των Buttons μπορούμε να την αυξήσουμε/μιώσουμε. Ο κώδικας δόθηκε το ακαδημαϊκό έτος 2021-2022 ως εργασία στο μάθημα Ενσωματωμένων Συστημάτων Εργαστήριο στο 7ο εξάμηνο την ακαδημαϊκή χρονιά 2021-2022.


EN: A program that can activate the internal thermal sensor of the MSP430 to show us the temperature and with the usage of the Buttons we can increase it/decrease it. This code was given as an assignment during the academic year of 2021-2022 in the lesson of Embedded Systems in the 7th Semester during the academic year 2021-2022.


