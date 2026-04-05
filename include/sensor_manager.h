#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>

// declare our sensor functions here:
void initSensors();
int readLightLevel();
float readTemperature();

#endif