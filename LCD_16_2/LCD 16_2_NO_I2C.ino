
// BY ALEXANDROS PANAGIOTAKOPOULOS - ALEXANDROSPANAG.GITHUB.IO
// LCD || ARDUINO
//_____________________________
// VSS - GND
// VDD - 5V
// VO - D6
// RS - D12
// RW - GND
// E  - D11
// D4 - D5
// D5 - D4
// D6 - D3
// D7 - D2
// A - 5V
// K - GND

#include <LiquidCrystal.h> 


int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

 void setup()
 {
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
  } 
     void loop()
 { 
     lcd.setCursor(0, 0);
     lcd.print("ARDUINO IS FUN!");
   
    lcd.setCursor(0, 1);
     lcd.print("GitHub Mood");
     delay(10000); //Necessary Delay make sure it's above at least 3000 (3s) for optimal results
 }