# Modular Embedded Control Platform (Arduino UNO)

This is a real-time embedded control and signal processing platform built on an Arduino UNO R3. 

Most Arduino projects are single-file scripts. The goal of this project is to build a proper embedded software architecture using a Hardware Abstraction Layer (HAL), a Finite State Machine (FSM), and a closed-loop control system. It maps "quantum-inspired" control concepts (measurement, state estimation, disturbance injection, and feedback correction) onto physical hardware.

## The Hardware Challenge & Pin Multiplexing
The UNO only has 12 usable digital/analog pins for this project (reserving TX/RX). The system requires 15 pins for all sensors, displays, and motors. 

To solve this hardware constraint, the architecture uses a **74HC595 Shift Register** as a serial bottleneck. The 4-pin Stepper Motor and status LEDs are driven through the shift register using bit-masking and shadow registers, freeing up enough pins to run the LCD1602 and the analog sensor suite natively.

## Hardware Inventory
**Sensors (Measurement Layer):**
* Ultrasonic Sensor (Distance / Spatial disturbance)
* DHT11 & Thermistor (Thermal disturbance)
* 2x Photoresistors (Optical state)
* Potentiometer (Manual target setpoint)

**Actuators (Control Effort & Readout):**
* SG90 Servo (Proportional control output)
* Stepper Motor + ULN2003 (Discrete state changes, driven via 74HC595)
* LCD1602 (Primary telemetry)
* LEDs & Active Buzzer (Fault / Mode indicators)

## Development Roadmap
- [x] **Milestone 1:** Hardware Bring-Up & Shift Register Validation
- [x] **Milestone 2:** Modular Driver Layer (C++ Headers/Classes)
- [ ] **Milestone 3:** System Orchestration (Finite State Machine)
- [ ] **Milestone 4:** Feedback Control Core (PID/PI loop)
- [ ] **Milestone 5:** Signal Generation & Disturbance Testing
- [ ] **Milestone 6:** Sensor Fusion
- [ ] **Milestone 7:** Python Telemetry Logging & Final Integration

## Setup
Built using VS Code and PlatformIO.
