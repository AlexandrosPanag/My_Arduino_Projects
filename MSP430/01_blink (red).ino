#define LED RED_LED
//Αυτά είναι σχόλια
//ορίζουμε εναλλακτικό χρώμα που θέλουμε στο led να αλλάξει.

  
void setup() {                
  // initialize the digital pin as an output - ορίζουμε το ψηφιακό pin σαν έξοδο.
  pinMode(LED, OUTPUT);     
}

// the loop routine runs over and over again forever - ατέρμων βρόγχος :
void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level) - άνοιγμα led (χρόνος προσπέλασης για να ανάψει το led)
  delay(1000);               // wait for a second - αναμονή ενός δευτερολέπτου.
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW - κλείσιμο led (χρόνος προσπέλασης για να σβήσει το led).
  delay(1000);               // wait for a second - αναμονή ενος δευτερολέπτου.
}
