/*
 * Created by Alexandros Panagiotakopoulos
*/

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i=1; i <=9; i++){
    int r=random(0,100);
    Serial.print(r);
    Serial.print(" ");
    }
    Serial.println();
}
