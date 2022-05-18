Adafruit HTU21D_F Temperature & Humidity Sensor
-------------------------------------

![](https://raw.githubusercontent.com/AlexandrosPanag/My_Arduino_Projects/main/HTU21D_F/htu21d_f.jpg)


This I2C digital humidity sensor is an accurate and intelligent alternative to the much simpler Humidity and Temperature Sensor - SHT15 Breakout It has a typical accuracy of ±2% with an operating range that's optimized from 5% to 95% RH. Operation outside this range is still possible - just the accuracy might drop a bit. The temperature output has an accuracy of ±1°C from -30~90°C. If you're looking to measure temperature more accurately, we recommend the MCP9808 High Accuracy I2C Temperature Sensor Breakout Board.

Such a lovely chip - so we spun up a breakout board that includes the Filtered version (the white bit of plastic which is a PTFE filter to keep the sensor clean), a 3.3V regulator and I2C level shifting circuitry. This lets you use it safely with any kind of microcontroller with 3.3V-5V power or logic.

To get you going fast, we spun up a custom made PCB in the STEMMA QT form factor, making them easy to interface with. The STEMMA QT connectors on either side are compatible with the SparkFun Qwiic I2C connectors.

SOURCE: https://www.adafruit.com/product/1899


HTU21D_F Initialization
--------------------------------------------------------

This project was made in order to initialize the HTU21D_F Temperature Sensor that can read & print both the humidity and the current temperature
