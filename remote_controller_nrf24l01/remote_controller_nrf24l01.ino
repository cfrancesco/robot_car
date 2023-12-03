#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "joystick.h"

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

Joystick joystick(A1, A0);

void loop() {
  joystick.update();
    long unsigned int code = 0;
    int x = joystick.getRawX();
    int y = joystick.getRawY();
    // x and y have max values of 1023, so we can use 10 bits to represent them
    code = (unsigned long)x << 10;
    code = code | y;
  radio.write(&code, sizeof(code));
  delay(100);
}