#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();


void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => Digital Pin 2
}
void loop() {
  
  if (mySwitch.available()) {

    // }
    long unsigned int code = mySwitch.getReceivedValue();
    int received_x = code >> 10;
    int received_y = code & 0x3FF;
    Serial.print("X: ");
    Serial.println(received_x);
    Serial.print(" Y: ");
    Serial.println(received_y);
    mySwitch.resetAvailable();
    
  }
  delay(100);
}