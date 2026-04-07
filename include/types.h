// include/types.h
#pragma once

// ==========================================
// hardware measurement state
// ==========================================
struct SensorData {
    float temperature;   // from DHT11 / Thermistor
    float humidity;      // from DHT11
    int lightLevel;      // from photoresistor 
    float distanceCm;    // from ultrasonic
};

// ==========================================
// user intent state
// ==========================================
struct CommandState {
    int setpoint;  // from potentiometer 
    int joystickX;       // from Joystick VRx
    int joystickY;       // from Joystick VRy
    bool modeChangeRequested;
};

// ==========================================
// system operating modes
// ==========================================
// used by the Finite State Machine (FSM)
enum SystemMode {
    MODE_BOOT,
    MODE_IDLE,
    MODE_MANUAL,
    MODE_AUTO,
    MODE_TEST,
    MODE_FAULT
};

// ==========================================
// logical control state
// ==========================================
// bridges inputs to outputs.
struct ControlState {
    SystemMode currentMode;
    float currentError;      // difference between target and measured state
    float controlEffort;     // the computed correction (e.g., PID output)
    bool isFaultActive;      // true if sensors disconnect or values go out of bounds
};