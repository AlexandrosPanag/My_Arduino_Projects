// This example is based on the greek book "Ανάπτυξη εφραμογών με το arduino" των Παναγιώτη Παπαζόγλου & Σπύρος Πολυχρώνης
const int Red_Led_Pin = 5; //red led pin
const int Yellow_Led_Pin = 4; //yello led pin
const int Green_Led_Pin = 3; // green led pin

//traffic light duration
const unsigned int Red_Delay = 8000;
const unsigned int Yellow_Delay = 2000;
const unsigned int Green_Delay = 6000;

void setup(){
// Declaring the outputs
pinMode(Green_Led_Pin, OUTPUT);
pinMode(Yellow_Led_Pin, OUTPUT);
pinMode(Red_Led_Pin, OUTPUT);
}


void loop(){
//turn on the green led
digitalWrite(Green_Led_Pin, HIGH);
delay(Green_Delay);

//turn off the green led
digitalWrite(Green_Led_Pin, LOW);

//turn on the yellow led
digitalWrite(Yellow_Led_Pin, HIGH);
delay(Yellow_Delay);

//turn off the yellow led
digitalWrite(Yellow_Led_Pin, LOW);

//turn on the red led
digitalWrite(Red_Led_Pin, HIGH);
delay(Red_Delay);

//turn off the red led
digitalWrite(Red_Led_Pin, LOW);
}
