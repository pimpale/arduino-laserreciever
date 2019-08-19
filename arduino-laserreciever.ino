#include <SoftwareSerial.h>

const byte rxPin = 3;
const byte txPin = 2; // Reciever is connected to pin 3

SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  Serial.begin(9600);
  mySerial.begin(300);
  mySerial.listen();

  while(true) {
    if(mySerial.available()) {
      Serial.write(mySerial.read());
    }
  }

}



// loop is too slow
void loop() {
  
}
