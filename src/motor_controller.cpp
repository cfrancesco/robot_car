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

# TODO: Make these constants configurable
int JOYSTICK_MID = 512;
int JOYSTICK_MAX = 1023;

void MotorController::calculateMotorSpeedsForDirection(int speed, int xAxis, int& motorSpeedA, int& motorSpeedB) {
    if (xAxis > JOYSTICK_MID) {  // Turn right
        motorSpeedA = speed;
        motorSpeedB = speed - map(xAxis, JOYSTICK_MID+1, JOYSTICK_MAX, 0, speed);
    } else if (xAxis < JOYSTICK_MID) {  // Turn left
        motorSpeedA = speed - map(xAxis, 0, JOYSTICK_MID-1, speed, 0);
        motorSpeedB = speed;
    } else {
        motorSpeedB = speed;
        motorSpeedA = speed;
    }
    // // print outputs
    // Serial.print("Motor A: ");
    // Serial.print(motorSpeedA);
    // Serial.print(" | Motor B: ");c
    // Serial.println(motorSpeedB);
}

void MotorController::setMotorDirectionAndSpeed(int speed, int xAxis) {
    int motorSpeedA, motorSpeedB;

    if (speed > 0) {  // Forward
        calculateMotorSpeedsForDirection(speed, xAxis, motorSpeedA, motorSpeedB);
    } else {  // Backward
        calculateMotorSpeedsForDirection(speed, xAxis, motorSpeedB, motorSpeedA);
    }
    inputMotorSpeed(motorSpeedA, motorSpeedB);
}

void MotorController::setMotorSpeedFromJoystick(int x, int y, int speed) {
        if (y < JOYSTICK_MID) {
            speed = -speed;  // Reverse for negative Y values
        }
        setMotorDirectionAndSpeed(speed, x);
    }