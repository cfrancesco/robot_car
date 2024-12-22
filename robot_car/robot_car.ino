#include "Arduino.h"
#include "motor_controller.h"
#include "communication.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "joystick.h"

RF24 radio(6, 10); // CE, CSN

MotorController motor(3, 4, 5, 9, 7, 8);

const byte address[6] = "00001";
const bool DEBUG = false;
void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
}

void loop() {
    if (radio.available()) {
        long unsigned int code;
        unsigned int x;
        unsigned int y;
        radio.read(&code, sizeof(code));
        twoNumberUnpacking(code, x, y);
        motor.setMotorSpeedFromJoystick(x - Joystick::JOYSTICK_MID, y - Joystick::JOYSTICK_MID);
    }
    else {
        motor.setMotorSpeedFromJoystick(0, 0);
        Serial.print("No signal.");
    }
    delay(COMMUNICATION_DELAY); // Optional delay for stability and reduced serial traffic.
    if (DEBUG) {
        delay(1000);
    }
}