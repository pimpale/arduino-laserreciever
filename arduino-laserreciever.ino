const int ledPin = 3;    // LED connected to digital pin 13
const char* wordThing = "Yes";

void setup() {
  pinMode(ledPin, OUTPUT);    // sets the digital pin as output
}

void loop() {
  for(int i = 0; i < strlen(wordThing); i++) {
    unsigned char byteThing = wordThing[i];
    out_byte(byteThing);
  }
  
}

void out_byte(unsigned char out) {
  
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(out);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(256 - out);
}
