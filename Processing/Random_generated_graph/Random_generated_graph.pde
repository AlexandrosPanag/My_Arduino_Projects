int xPos; //current value on X axis
int oldXpos=0; //keeper of the value of x axis
int oldxint; //keeping the last generated value on the graph
int dx=20; //the graph will start with a loss of 20 pixels on the graph

void setup(){
size(500 , 250); //setting the size of the graph
background(255,255,255); //setting the background
line(0,100,500,100); //white color on the background
xPos=dx; //original value on the x axis
}

void draw(){
int test = int (random(100));
int ixt=int(map((float(test)),0,100,-50,50)); //generating the graph size from 0,100 to -50,50

stroke(0,0,0); //adjusting the width
line(oldXpos,100+oldxint,xPos,100+ixt); //printing the values on the graph

oldXpos=xPos; //adjusting the coordinates properly
oldxint=ixt; //keeping the current value so it can be used to the next repeat

if(xPos >= width-dx){ //if we have reached the limit of the X axis then we begin all over again
xPos=dx;
}
else  //otherwise we move forward normally
{
xPos++;
}

}
