#include "Arduino.h"
#include "src/motor_controller.h"

MotorController motor(10, 6, 7, 9, 5, 4);

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println();
    Serial.println("LOG START");
    motor.inputMotorSpeed(0, 0);

    delay(200); // Optional delay for stability and reduced serial traffic.
}