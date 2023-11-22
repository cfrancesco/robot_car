#include <RCSwitch.h>
#include "joystick.h"


RCSwitch mySwitch = RCSwitch();

#define Button1 2
int code1 = 0;
int code2 = 0;

void setup()
{
  Serial.begin(9600);
//   mySwitch.setRepeatTransmit(10);
  pinMode(Button1, INPUT_PULLUP);
  // Transmitter is connected to Arduino Pin #0
  mySwitch.enableTransmit(10);
}
Joystick joystick(A1, A0);
void loop() {
    joystick.update();
    Serial.println();
    Serial.println("LOG START");
    Serial.print("X: ");
    Serial.print(joystick.getRawX());
    Serial.print(" Y: ");
    Serial.print(joystick.getRawY());
    Serial.print(" Magnitude: ");
    Serial.println(joystick.getMagnitude());
    long unsigned int code = 0;
    int x = joystick.getRawX();
    int y = joystick.getRawY();
    // x and y have max values of 1023, so we can use 10 bits to represent them
    code = (unsigned long)x << 10;
    code = code | y;
    mySwitch.send(code, 24);
    delayMicroseconds(20);
    Serial.println("LOG END");
//   if (digitalRead(Button1) == LOW) {
//     int x = 510;
//     int y = 610;
//     long unsigned int code = 0;
//     // x and y have max values of 1023, so we can use 10 bits to represent them
//     code = (unsigned long)x << 10;
//     code = code | y;
//     mySwitch.send(code, 24);
//     delayMicroseconds(20);
//     Serial.print("Button 1 is pressed and sends code: ");
//     Serial.println(code);
//     // now decode for debugging purposes
//     int received_x = code >> 10;
//     int received_y = code & 0x3FF;
//     Serial.print("Received x: ");
//     Serial.print(received_x);
//     Serial.print(" y: ");
//     Serial.println(received_y);
//   }
}