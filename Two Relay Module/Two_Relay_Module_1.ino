int RelayPinOne = 12;
int RelayPinTwo = 11;

void setup() {
	// Set RelayPin as an output pin
	pinMode(RelayPinOne, OUTPUT);
	pinMode(RelayPinTwo, OUTPUT);
}

void loop() {
	// Let's turn on the relay...
	digitalWrite(RelayPinOne, LOW);
	delay(3000);
	digitalWrite(RelayPinTwo, HIGH);
	delay(3000);
	
	// Let's turn off the relay...
	digitalWrite(RelayPinOne, LOW);
	delay(3000);
	digitalWrite(RelayPinTwo, HIGH);
	delay(3000);
}
