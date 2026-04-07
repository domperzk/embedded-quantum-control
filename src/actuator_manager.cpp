#include <Arduino.h>
#include "actuator_manager.h"
#include "config.h"

// global variables 
byte shadow = 0b00000000; 
byte motorStep[4] = {0b1000, 0b0100, 0b0010, 0b0001};

void writeRegister() {
    digitalWrite(PIN_SR_LATCH, LOW);
    shiftOut(PIN_SR_DATA, PIN_SR_CLOCK, MSBFIRST, shadow);
    digitalWrite(PIN_SR_LATCH, HIGH);
}

void initActuators() {
    pinMode(PIN_SR_LATCH, OUTPUT);
    pinMode(PIN_SR_CLOCK, OUTPUT);
    pinMode(PIN_SR_DATA, OUTPUT);
    writeRegister(); // initialize to all OFF
}

void updateActuators() {
    unsigned long currentMillis = millis();
    bool hardwareNeedsUpdate = false; // resets to false every loop

    // variables that retain their memory 
    static unsigned long previousStepperTime = 0;
    static unsigned long previousLedTime = 0;
    static byte stepIndex = 0;
    static bool ledState = false;
    // stepper motor (every 10ms)
    if (currentMillis - previousStepperTime >= 10) {
        previousStepperTime = currentMillis; // Reset the timer

        // grab the next step pattern
        byte currentMotor = motorStep[stepIndex];
        
        // clear Q4-7
        shadow = shadow & MASK_STEPPER_CLEAR;
        currentMotor = currentMotor << 4;
        shadow = shadow | currentMotor;

        // next step
        stepIndex++;
        if (stepIndex >= 4) { stepIndex = 0; }

        hardwareNeedsUpdate = true; 
    }

    // status LED (every 500ms)
    if (currentMillis - previousLedTime >= 500) {
        previousLedTime = currentMillis; 

        ledState = !ledState; 

        if (ledState == true) {

            shadow = shadow | 0b00000001;

        } else {
            shadow = shadow & 0b11111110;
        }

        hardwareNeedsUpdate = true; // Tell the system we changed the shadow
    }

    // hardware bottleneck
    if (hardwareNeedsUpdate == true) {
        writeRegister(); 
    }
}