#include "Arduino.h"
#include "motor_controller.h"
#include "communication.h"
#include "joystick.h"

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
    // Serial.print("Motor A: ");
    // Serial.println(motorSpeedA);
    // Serial.print("Motor B: ");
    // Serial.println(motorSpeedB);
    int motorSpeedA_map = map(abs(motorSpeedA), 0, Joystick::JOYSTICK_MID, 0, 255);
    int motorSpeedB_map = map(abs(motorSpeedB), 0, Joystick::JOYSTICK_MID, 0, 255);
    // Serial.print("Motor mapped A: ");
    // Serial.println(motorSpeedA);
    // Serial.print("Motor mapped B: ");
    // Serial.println(motorSpeedB);
    analogWrite(enA, motorSpeedA_map);
    analogWrite(enB, motorSpeedB_map);
    digitalWrite(in1, motorSpeedA >= 0);
    digitalWrite(in2, motorSpeedA < 0);
    digitalWrite(in3, motorSpeedB < 0);
    digitalWrite(in4, motorSpeedB >= 0);
}

// TODO: Make these constants configurable

void MotorController::calculateMotorSpeedsForDirection(int speed, int xAxis, int& motorSpeedA, int& motorSpeedB) {
    long mapval = map(abs(xAxis), 0, Joystick::JOYSTICK_MID - 1, 0, speed);
    if (xAxis > 0) {  // Turn right
        motorSpeedA = speed;
        motorSpeedB = speed - mapval;
    } else if (xAxis < 0) {  // Turn left
        motorSpeedA = speed - mapval;
        motorSpeedB = speed;
    } else {
        motorSpeedB = speed;
        motorSpeedA = speed;
    }
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

void MotorController::setMotorSpeedFromJoystick(int x, int speed) {
        // Serial.print("x: ");
        // Serial.println(x);
        // Serial.print("speed: ");
        // Serial.println(speed);
        setMotorDirectionAndSpeed(speed, x);
    }