/*********
 By Alexandros Panagiotakopoulos - alexandrospanag.github.io
*********/

#include <vector>
//create a vector full of numbers (integer)
std::vector<int> numbers;
void setup() 
{
  Serial.begin(9600); //initialize the serial baud rate to 9600 bauds/sec
}
void loop() {
  Serial.println("Compiling!");
  //push back an elements
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);
  //printing all the elements
  for (int i = 0; i < numbers.size(); i++)
  {
    Serial.println(numbers.at(i));
  }
  //clearing the elements
  Serial.print("Clearing! The vector contains the following elements now: ");
  Serial.println(numbers.empty());
  delay(5000); //delay 5 seconds before running again
}