void setup(){
size(500,500);
noLoop();
}

void draw()
{
  background(255,255,255);
  float xpi; //takes values from 0 to 2π
  float y=250; //takes the start from the graph for Y axis
  int x=20; //begin the graph from the starting point
  int f=30; //begin point from the X axis
  
  line(20,10,20,460); //Y-axis
  line(10,250,500,250); //X-axis
  
  for(xpi=0; xpi<=(2*PI); xpi+=0.001)
  {
  point(x,y-sin(f*xpi)*100);
  x++;
  }
}
