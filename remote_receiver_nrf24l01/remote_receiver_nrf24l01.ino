/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <communication.h>
#include "joystick.h"

RF24 radio(8, 9); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
bool DEBUG = true;
void loop() {
  if (radio.available()) {
    long unsigned int code;
    unsigned int x;
    unsigned int y;
    unsigned int z;
    radio.read(&code, sizeof(code));
    threeNumberUnpacking(code, x, y, z);
    Serial.print("x: ");
    Serial.println(x);
    Serial.print("y: ");
    Serial.println(y);
    Serial.print("z: ");
    Serial.println(z);
  }
  delay(COMMUNICATION_DELAY); // Optional delay for stability and reduced serial traffic.
  if (DEBUG) {
    delay(1000);
  }
}