#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "Arduino.h"

class Joystick {
/*
This class represents a joistick that reads value in a square, but the shaft moves in a circle.
Class variables:
- neutralBuffer is the buffer around the neutral position of the joystick.
- (xAxis, yAxis) is the buffered (x, y) value of the joystick.
- (xAxisCircle, yAxisCircle) is (xAxis, yAxis) mapped to the unit circle.
- magnitude is calculated using the circle values and represent the distance of the (xAxisCircle,yAxisCircle) point from the origin.
*/
// TODO: x and y are functionally exchanged in this class. Fix this.
private:
    const int xAxisPin;
    const int yAxisPin;
    static const int JOYSTICK_MID = 512;
    static const int JOYSTICK_MAX = 1023;
    int xAxis = JOYSTICK_MID;
    int yAxis = JOYSTICK_MID;
    float xAxisCircle = 0.0;
    float yAxisCircle = 0.0;
    int neutralBuffer = 20;
    int magnitude = 0;
    int readX();
    int readY();
    int bufferJoystickNeutral(int v);
    void mapSquareToCircle(float x, float y, float &xCircle, float &yCircle);
    int evalMagnitude();
public:
    Joystick(int x, int y);
    float getX();
    float getY();
    int getMagnitude();
    void update();
    void setRawXY(int x, int y);
    int getRawY();
    int getRawX();
};
#endif