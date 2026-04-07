#pragma once
#include <Arduino.h>
// ==========================================
// PIN DEFINITIONS: ACTUATORS
// ==========================================
// 74HC595 Shift Register (Controls Stepper, LEDs, Buzzer)
const int PIN_SR_LATCH = 8;  // STCP
const int PIN_SR_DATA  = 11; // DS
const int PIN_SR_CLOCK = 12; // SHCP

// Servo Motor
const int PIN_SERVO = 3;     // Must be PWM capable

// ==========================================
// PIN DEFINITIONS: DISPLAY (LCD1602)
// ==========================================
const int PIN_LCD_RS = 2;
const int PIN_LCD_EN = 4;
const int PIN_LCD_D4 = 5;
const int PIN_LCD_D5 = 6;
const int PIN_LCD_D6 = 7;
const int PIN_LCD_D7 = 13;

// ==========================================
// PIN DEFINITIONS: SENSORS & INPUTS
// ==========================================
// Ultrasonic
const int PIN_US_TRIG = 9;
const int PIN_US_ECHO = 10;

// Analog / Mixed-Signal Inputs
const int PIN_DHT11   = A0;  // Digital 1-wire protocol
const int PIN_THERM   = A1;  // Analog
const int PIN_LDR     = A2;  // Analog
const int PIN_POT     = A3;  // Analog (Target Setpoint)
const int PIN_JOY_X   = A4;  // Analog (Menu/Mode Navigation)
const int PIN_JOY_Y   = A5;  // Analog (Menu/Mode Navigation)

// ==========================================
// SHIFT REGISTER OUTPUT MAPPING (Q0-Q7)
// ==========================================
// Used in actuator_manager.cpp
const byte MASK_STEPPER_CLEAR = 0b00001111; // Clears Q4-Q7
const byte MASK_LED_STATUS    = 0b00000001; // Q0
const byte MASK_BUZZER        = 0b00000010; // Q1

// ==========================================
// TIMING CONSTANTS (Milliseconds)
// ==========================================
const unsigned long TIMING_STEPPER_MS     = 10;
const unsigned long TIMING_LED_BLINK_MS   = 500;
const unsigned long TIMING_SENSOR_POLL_MS = 250; // DHT11 is slow, do not poll faster than 250ms
const unsigned long TIMING_LCD_REFRESH_MS = 200; // Prevents screen flickering