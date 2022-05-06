/*
 * Created by Alexandros Panagiotakopoulos
*/


void setup() {
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  String a = "This message was originally lower case"; //creating a lower case message
  String b = "THIS MESSAGE WAS ORIGINALLY UPPER CASE"; //creating an upper case message
  
  a.toUpperCase(); //we turn a into an upper case message
  b.toLowerCase(); //we turn b into an lower case message
  
  Serial.println(a); //we print a into the serial port
  Serial.println(b); //we print b into the serial port

   // Working with more strings...
   
   int x = 10; //declaring an INTEGER number 10
   float y = 6.3; // declaring a FLOAT (or real) number 6,3

   String str1 = String(x); //str1 becomes 10
   String str2 = String(7); //str2 becomes 7 
   String str3 = str1 + str2 + String(y); //finally we add str3 = 10+7+6.3 = 1076.3 but
   //becase arduino prints the numbers into decimal format it becomes 1076.30

   Serial.println(str3); //Lastly we print str3 which equals to 1076.30 
  
  
  delay(10000); //Lastly, we delay the code for 10 seconds
}
