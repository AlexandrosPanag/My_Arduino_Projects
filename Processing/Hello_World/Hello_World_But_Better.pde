void setup()
{
  size(200, 200); //changing the window size
  smooth(); //enabling anti-analyzing
  fill(0); //black color on the text line
  textFont(createFont("SansSerif",18)); //adjusting the text font type
  textAlign(CENTER); //aligning the text into the center
  noLoop(); //the code runs only once
}

void draw(){
  text("Hello World!", width/2, height/2); //printing the hello world text
}
