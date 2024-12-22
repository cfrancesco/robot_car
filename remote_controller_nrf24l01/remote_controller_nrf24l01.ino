#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "joystick.h"
#include "communication.h"

bool DEBUG = false;

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  if (DEBUG) {
    Serial.begin(9600);
  }
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
  // unsigned int z = joystick.getMagnitude();
  // unsigned int x_int = floatToUInt(x);
  // unsigned int y = floatToUInt(y);
  code = twoNumberPacking(x, y);
  radio.write(&code, sizeof(code));
  if (DEBUG) {
    Serial.print("x: ");
    Serial.println(x);
    Serial.print("y: ");
    Serial.println(y);
    Serial.print("code: ");
    Serial.println(code);
    unsigned int x_received;
    unsigned int y_received;
    twoNumberUnpacking(code, x_received, y_received);
    Serial.print("x_received: ");
    Serial.println(x_received);
    Serial.print("y_received: ");
    Serial.println(y_received);
    delay(1000);
  }
  // delay(COMMUNICATION_DELAY);
}