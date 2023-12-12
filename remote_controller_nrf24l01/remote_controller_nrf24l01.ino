#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "joystick.h"
#include "communication.h"

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
  float x = joystick.getX();
  float y = joystick.getY();  // -1, 1 valued
  unsigned int z = joystick.getMagnitude();
  unsigned int x_int = floatToUInt(x);
  unsigned int y_int = floatToUInt(y);
  code = threeNumberPacking(x_int, y_int, z);
  radio.write(&code, sizeof(code));
  delay(COMMUNICATION_DELAY);
}