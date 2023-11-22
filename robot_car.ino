#include "Arduino.h"
#include "src/motor_controller.h"
#include "src/joystick.h"
#include <RCSwitch.h>

MotorController motor(10, 6, 7, 9, 5, 4);
Joystick joystick(A1, A0);
RCSwitch mySwitch = RCSwitch();

void setup() {
    Serial.begin(9600);
    mySwitch.enableReceive(0);  
}

void loop() {
    Serial.println();
    Serial.println("LOG START");
    if (mySwitch.available()) {
        long unsigned int code = mySwitch.getReceivedValue();
        int received_x = code >> 10;
        int received_y = code & 0x3FF;
        joystick.setRawXY(received_x, received_y);
        Serial.print("X: ");
        Serial.print(joystick.getX());
        Serial.print(" Y: ");
        Serial.print(joystick.getY());
        Serial.print(" Magnitude: ");
        Serial.println(joystick.getMagnitude());
        Serial.println("LOG END");
        motor.inputMotorSpeed(joystick.getMagnitude(), 0);
        mySwitch.resetAvailable();
    }
    delay(30); // Optional delay for stability and reduced serial traffic.
}