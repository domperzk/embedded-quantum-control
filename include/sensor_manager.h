#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "types.h"

#include <Arduino.h>

// declare our sensor functions here:
void initSensors();
void updateSensors();
SensorData getSensorState();

#endif