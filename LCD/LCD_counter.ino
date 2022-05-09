/*********
 By Alexandros Panagiotakopoulos
*********/

#include <LiquidCrystal_I2C.h>



// set the LCD number of columns and rows
int time_count_second=0; //Declaring a time counter for each second
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void loop(){
  //random number generator
   time_count_second++; //adding each second on the time counter
    
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  lcd.print(time_count_second);   // print message
  delay(1000);    // Wait one second
  lcd.clear();   // clears the display to print new message
}
