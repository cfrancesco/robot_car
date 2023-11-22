#include "joystick.h"

int Joystick::readX() {
    return analogRead(xAxisPin);
}

int Joystick::readY() {
    return analogRead(yAxisPin);
}
int Joystick::evalMagnitude() {
    float _magnitude = sqrt(xAxisCircle * xAxisCircle + yAxisCircle * yAxisCircle);
    // float scale = static_cast<float>(JOYSTICK_MAX);
    return static_cast<int>(_magnitude * JOYSTICK_MAX);
}

int Joystick::bufferJoystickNeutral(int v) {
    /*
    This function is used to buffer the neutral position of the joystick.
    The joystick is not always perfectly centered when in neutral position.
    This function will map the values around the neutral position to the neutral position.
    */
    if (v >= JOYSTICK_MID + neutralBuffer) {
        v = map(v, JOYSTICK_MID + neutralBuffer, JOYSTICK_MAX, JOYSTICK_MID, JOYSTICK_MAX);
    }
    else if (v <= JOYSTICK_MID - neutralBuffer) {
        v = map(v, 0, JOYSTICK_MID - neutralBuffer, 0, JOYSTICK_MID);
    }
    else {
        v = JOYSTICK_MID;
    }
    return v;
}



void Joystick::mapSquareToCircle(float x, float y, float &xCircle, float &yCircle) {
    /*
    The joystick has a square range of motion, but we want to map it to a circle, which is the 
    physical motion of the shaft.
    */
    // Normalize x and y to [-1, 1]
    float xNormalized = (x == JOYSTICK_MID) ? 0.0 : (2 * x / JOYSTICK_MAX) - 1;
    float yNormalized = (y == JOYSTICK_MID) ? 0.0 : (2 * y / JOYSTICK_MAX) - 1;


    // Compute the distance to origin 0 <= r <= sqrt(2)~1.414
    float r = sqrt(xNormalized * xNormalized + yNormalized * yNormalized);

    // Calculate scaling factor
    float scalingFactor = (r == 0) ? 1.0 : min(r, 1.0) / r;


    // Apply scaling factor
    xCircle = xNormalized * scalingFactor;
    yCircle = yNormalized * scalingFactor;

}


Joystick::Joystick(int x, int y) : xAxisPin(x), yAxisPin(y) {
    pinMode(xAxisPin, INPUT);
    pinMode(yAxisPin, INPUT);
}

void Joystick::update() {
    int x = readX();
    int y = readY();
    xAxis = bufferJoystickNeutral(x);
    yAxis = bufferJoystickNeutral(y);
    mapSquareToCircle(xAxis, yAxis, xAxisCircle, yAxisCircle);
    magnitude = evalMagnitude();
}

float Joystick::getX() {
    return xAxisCircle;
}

float Joystick::getY() {
    return yAxisCircle;
}

int Joystick::getMagnitude() {
    return magnitude;
}



