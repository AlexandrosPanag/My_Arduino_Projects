Adafruit BME 280
--------

In case your ESP32 model is not the same as the one i used and you have a trouble identifying the appropriate MISO/ MOSI etc SPI Pins i highly enourage you to visit the DEBUG example that i've made which can be found at the link bellow

-> https://github.com/AlexandrosPanag/My_ESP32_Projects/tree/main/DEBUG/SPI_DEBUG  <-

![](https://raw.githubusercontent.com/AlexandrosPanag/My_Arduino_Projects/main/BME280/BME280.jpg)


Bosch has stepped up their game with their new BME280 sensor, an environmental sensor with temperature, barometric pressure and humidity! This sensor is great for all sorts of indoor environmental sensing and can even be used in both I2C and SPI!

This precision sensor from Bosch is the best low-cost sensing solution for measuring humidity with ±3% accuracy, barometric pressure with ±1 hPa absolute accuraccy, and temperature with ±1.0°C accuracy. Because pressure changes with altitude, and the pressure measurements are so good, you can also use it as an altimeter with  ±1 meter or better accuracy!

The BME280 is the next-generation of sensors from Bosch, and is the upgrade to the BMP085/BMP180/BMP183 - with a low altitude noise of 0.25m and the same fast conversion time. It has the same specifications, but can use either I2C or SPI. For simple easy wiring, go with I2C. If you want to connect a bunch of sensors without worrying about I2C address collisions, go with SPI.


<b> THIS SOURCE WAS TAKEN DIRECTLY & CAN BE FOUND HERE: https://www.adafruit.com/product/2652 </b>

For a more complete documentation, instructions you can check out this link : https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/arduino-test


BME280 Initialization
-------------

A project made to initialize the Adafruit BME280 sensor, print the temperature, the pressure , the approximate altitude from the sea level pressure and the current humidity every 10 seconds
