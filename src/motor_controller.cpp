#include "Arduino.h"
#include "motor_controller.h"

MotorController::MotorController(int a, int i1, int i2, int b, int i3, int i4)
        : enA(a), in1(i1), in2(i2), enB(b), in3(i3), in4(i4) {
        pinMode(enA, OUTPUT);
        pinMode(enB, OUTPUT);
        pinMode(in1, OUTPUT);
        pinMode(in2, OUTPUT);
        pinMode(in3, OUTPUT);
        pinMode(in4, OUTPUT);
}

void MotorController::inputMotorSpeed(int motorSpeedA, int motorSpeedB) {
    analogWrite(enA, abs(motorSpeedA));
    analogWrite(enB, abs(motorSpeedB));
    digitalWrite(in1, motorSpeedA >= 0);
    digitalWrite(in2, motorSpeedA < 0);
    digitalWrite(in3, motorSpeedB >= 0);
    digitalWrite(in4, motorSpeedB < 0);
}