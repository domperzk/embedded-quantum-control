#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H
#include "types.h"

#include <Arduino.h>

// declare our input functions here:
void writeRegister();
void initActuators();
void updateActuators();

#endif