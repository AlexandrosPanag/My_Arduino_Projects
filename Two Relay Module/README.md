Two Relay Module
-----

This module contians two relays that are electrically isolated from the controlling input. The relays can be used to switch higher voltage and current loads than a microcontroller can traditionally accomplish.


Two Relay Module 1
------------

This program initializes both of the two relay module pins and makes them blink (more accurately, turns them on & off).

Useful Link : https://lastminuteengineers.com/two-channel-relay-module-arduino-tutorial/




Two Relay Module 2
------------


This program only initializes the first relay module pin and makes the relay pin activate if the DHT.temperature is above 25 celcius the relay pin activates otherwise, the relay pin will deactivate


Two Relay Module using the DHT11
-----------

This program is directly connected with the DHT11 sensor with a breadboard and with the Two Relay Module. Basically, our program finds the currect humididty levels & the temperature and if the temperature is above 25 Celcius both of the relays will turn on (HIGH) if the temperature is below or equal to 25 celcius, then the relays will turn off

Useful link which explains the very basics of the DHT11 sensor: https://github.com/AlexandrosPanag/My_Arduino_Projects/tree/main/DHT11
