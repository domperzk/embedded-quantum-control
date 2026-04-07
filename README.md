# Modular Embedded Control Platform (ATmega328P)

This project is a modular real-time embedded control platform built on the ATmega328P microcontroller.

Most small embedded projects are written as single-file scripts. The goal here is to build a structured embedded system with clear architecture, including a Hardware Abstraction Layer (HAL), a Finite State Machine (FSM), and a closed-loop control system.

The system maps control concepts such as measurement, state estimation, disturbance handling, and feedback correction onto physical hardware.

## Hardware Constraints & Pin Multiplexing

The ATmega328P has limited I/O, so careful pin management is required.  
The system requires more pins than are directly available for sensors, displays, and actuators.

To address this, the architecture uses a **74HC595 shift register** to extend output capability.  
The stepper motor and status LEDs are driven through the shift register using bit masking, freeing up pins for sensors and display modules.

## Hardware Overview

### Sensors (Measurement Layer)
- Ultrasonic sensor (distance / disturbance input)
- DHT11 and thermistor (temperature sensing)
- Photoresistors (light sensing)
- Potentiometer (manual input / setpoint)

### Actuators (Control & Output)
- SG90 servo (proportional control output)
- Stepper motor + ULN2003 (discrete control via shift register)
- LCD1602 (system telemetry)
- LEDs and buzzer (status and fault indication)

## Development Roadmap

- [x] **Milestone 1:** Hardware bring-up and shift register validation  
- [x] **Milestone 2:** Modular driver layer (HAL)  
- [ ] **Milestone 3:** System orchestration (Finite State Machine)  
- [ ] **Milestone 4:** Feedback control (P / PI / PID)  
- [ ] **Milestone 5:** Disturbance testing and signal patterns  
- [ ] **Milestone 6:** Multi-sensor integration  
- [ ] **Milestone 7:** Python telemetry logging and final integration  

## Setup

Built using VS Code and PlatformIO.
