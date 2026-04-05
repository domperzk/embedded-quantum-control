#include <Arduino.h>
#include "sensor_manager.h"

void initSensors() {
    // We will set up pin modes here later if needed
    Serial.println("Sensors initialized.");
}

int readLightLevel() {
    int photoresistor1 = analogRead(A2);

    return photoresistor1;
}

float readTemperature() {
    // We will leave this blank for now until the LDR works
    return 0.0;
}