#define readReciever() (!digitalRead(7))

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);

  // bitcounter is the bit we are currently on
  uint8_t bitCounter = 0; 
  uint8_t currentByte = 0;

  uint8_t currentStatus = LOW;

  int zcount = 0;
  while(true) {
    int status = readReciever();
    if(status ==0) {
      zcount++;
      if(zcount == 16) {
        break;
      }
    } else {
      zcount == 0;
    }
  }
  
  while(true) {
    delay(100);
    //set current status
    currentStatus = readReciever();

    currentByte |= (currentStatus==HIGH) << bitCounter; 
    bitCounter++;
    // if bit counter has reached byte maximum, print it out and clear it
    //Serial.println(currentStatus);
    if(bitCounter == 8) {
      Serial.println((char)currentByte);
      currentByte=0;
      bitCounter=0;
    }
  }
}



// loop is too slow
void loop() {}
