//Alexandros Panagiotakopoulos
void setup() {                
  // initialize the digital pin as an output - ορίζουμε το ψηφιακό pin σαν έξοδο αντίστοιχα με το χρώμα του.
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);          
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(RED_LED, HIGH);      // turn the RED LED on (HIGH is the voltage level) - άνοιγμα ΚΟΚΚΙΝΟ led (χρόνος προσπέλασης για να ανάψει το led)
  digitalWrite(GREEN_LED, HIGH);   // turn the GREEN LED on (HIGH is the voltage level) - άνοιγμα ΠΡΑΣΙΝΟ led (χρόνος προσπέλασης για να ανάψει το led)
  delay(1000);                    //  wait for a second - αναμονή ενός δευτερολέπτου.
  digitalWrite(RED_LED, LOW);    // turn the RED LED off by making the voltage LOW - κλείσιμο ΚΟΚΚΙΝΟΥ led μέσω χαμηλής τροφοδοσίας(χρόνος προσπέλασης για να σβήσει το led).
  digitalWrite(GREEN_LED, LOW); // turn the GREEN LED off by making the voltage LOW - κλείσιμο ΠΡΑΣΙΝΟΥ led μέσω χαμηλής τροφοδοσίας(χρόνος προσπέλασης για να σβήσει το led).
  delay(1000);                 // wait for a second - αναμονή ενός δευτερολέπτου.
}
