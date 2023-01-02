/*
  Original code was written by Rui Santos
  which can be found at the RandomNerdTutorials official website at: https://randomnerdtutorials.com/esp32-spi-communication-arduino/
*/

/*********
 Edited By Alexandros Panagiotakopoulos - alexandrospanag.github.io
*********/

//Find the default SPI pins for your board
//Make sure you have the right board selected in Tools > Boards
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("**********************************");
  Serial.print("MOSI: ");
  Serial.println(MOSI);
  
  Serial.print("MISO: ");
  Serial.println(MISO);
  
  Serial.print("SCK: ");
  Serial.println(SCK);
  
  Serial.print("SS: ");
  Serial.println(SS);  
  
  Serial.print("SCL: ");
  Serial.println(SCL); 

  Serial.print("SDA: ");
  Serial.println(SDA);

}

void loop() {
  // put your main code here, to run repeatedly:
}
