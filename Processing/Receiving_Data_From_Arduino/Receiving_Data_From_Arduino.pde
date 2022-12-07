import processing.serial.*; //including the necessary libraries


Serial myPort; //declaring the my port object

void setup(){ //set-up point
  myPort = new Serial(this , "COM4", 9600); //initializing the port serial, in my case it is COM4 yours may differ check your device manager
  myPort.bufferUntil('\n'); //read the serial until it reaches a new line / line break point
}

void draw(){} // we dont print anything on the draw screen

void serialEvent (Serial myPort)
{
  String inString = myPort.readStringUntil('\n'); //activating the serial receive from the serial port
  
  print(inString); //print the data
  
}
