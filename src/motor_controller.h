#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class MotorController {
private:
    const int enA;
    const int in1;
    const int in2;
    const int enB;
    const int in3;
    const int in4;

public:
    MotorController(int a, int i1, int i2, int b, int i3, int i4);
    void inputMotorSpeed(int motorSpeedA, int motorSpeedB);
    void calculateMotorSpeedsForDirection(int speed, int xAxis, int& motorSpeedA, int& motorSpeedB);
    void setMotorDirectionAndSpeed(int speed, int xAxis);
    void setMotorSpeedFromJoystick(int x, int y, int speed);
};

#endif