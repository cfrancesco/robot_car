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
    long unsigned int code = 0;
    int x = joystick.getRawX();
    int y = joystick.getRawY();
    // x and y have max values of 1023, so we can use 10 bits to represent them
    code = (unsigned long)x << 10;
    code = code | y;
    mySwitch.send(code, 24);
    delayMicroseconds(10);
}