#include <Arduino.h>
#include "sensor_manager.h"
#include "config.h"

SensorData cachedState;

void initSensors() {
    pinMode(PIN_US_TRIG, OUTPUT);
    pinMode(PIN_US_ECHO, INPUT);
    pinMode(PIN_LDR, INPUT);
}


void updateSensors() {
    unsigned long currentMillis = millis();
    static unsigned long previousPollTime = 0;
    if (currentMillis - previousPollTime >= TIMING_SENSOR_POLL_MS) {
        previousPollTime = currentMillis;
   
        cachedState.lightLevel = analogRead(PIN_LDR);
        // will add temp + humidity when ready
        digitalWrite(PIN_US_TRIG, LOW);
        delayMicroseconds(2);
        digitalWrite(PIN_US_TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(PIN_US_TRIG, LOW);

        unsigned long duration = pulseIn(PIN_US_ECHO, HIGH, 23200);
        cachedState.distanceCm = duration/58;
    }



} 

SensorData getSensorState() {
    return cachedState;
}

