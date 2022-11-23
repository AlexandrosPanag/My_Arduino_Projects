/*
 * Created by Alexandros Panagiotakopoulos
 * based on the example of page 675 from the book " ARDUINO ΑΛΓΟΡΙΘΜΙΚΗ, ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ ΚΑΙ ΕΦΑΡΜΟΓΕΣ" by Αριστείδης Σ. Μπούρας, Γιάννης Θ. Κάππος
*/

const byte BUZZER = 2; //Buzzer Pin connect it to D2

 // Duration
const int D1 = 250;
const int D2 = 500;
const int D3 = 750;
const int D4 = 1000;
const int D5 = 1250;
const int D6 = 1500;
const int D7 = 1750;
const int D8 = 2000;

 // Notes (Frequencies)
const int NTO6 = 1046;
const int RE6 =  1175;
const int MI6 =  1319;
const int FA6 =  1397;
const int SOL6 = 1568;
const int LA6 =  1760;
const int SI6 =  1976;
const int NTO7 = 2093;
const int RE7  = 2349;
const int MI7 =  2637;
const int FA7  = 2794;
const int SOL7 = 3136;
const int LA7  = 3520;
const int SI7 =  3951;

 // Song Composition as an array
const int SONG[]= {
   SOL6, D3,
   LA6, D1,
   SOL6, D2,
   LA6, D1,
   SOL6, D2,
   LA6, D1,
   MI6, D6,
   RE7, D4,
   RE7, D4,
   RE7, D2,
   SI6, D6,
   NTO7, D4,
   NTO7, D2,
   SOL6, D6,
   LA6, D2,
   NTO7, D3,
   SI6, D1,
   LA6, D2,
   SOL6, D2,
   MI6, D6,
   LA6, D4,
   LA6, D2,
   NTO7, D3,
   SI6, D1,
   LA6, D2,
   SOL6, D3,
   LA6, D1,
   SOL6, D2,
   MI6, D6,
   RE7, D4,
   RE7, D2,
   FA7, D3,
   RE7, D1,
   SI6, D2,
   NTO7, D6,
   MI7, D6,
   NTO7, D3,
   SOL6, D1,
   MI6, D2,
   SOL6, D3,
   FA6, D1,
   RE6, D2,
   NTO6, D8,  
};

 //Declaring the buzzer as an output
void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(SONG)/sizeof(SONG[0]); i+=2){
     tone(BUZZER, SONG[i]); //Note
     delay(SONG[i+1]); //Duration
     noTone(BUZZER);
     delay(10); // Small pause between each note
    }
}