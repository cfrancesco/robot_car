#include "Arduino.h"
#include "src/motor_controller.h"
#include "src/joystick.h"

MotorController motor(10, 6, 7, 9, 5, 4);
Joystick joystick(A1, A0);
void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println();
    Serial.println("LOG START");
    joystick.update();
    Serial.print("X: ");
    Serial.print(joystick.getX());
    Serial.print(" Y: ");
    Serial.print(joystick.getY());
    Serial.print(" Magnitude: ");
    Serial.println(joystick.getMagnitude());
    Serial.println("LOG END");
    motor.inputMotorSpeed(joystick.getMagnitude(), 0);
    delay(500); // Optional delay for stability and reduced serial traffic.
}