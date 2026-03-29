# Embedded Quantum Control Platform

## Project Overview
This project is a modular, real-time embedded control and signal processing platform built on an Arduino UNO R3. It maps fundamental quantum control concepts—such as state preparation, pulse sequences, and measurement decoherence—onto a deterministic embedded architecture. The system utilizes a multi-sensor array to estimate system state and applies closed-loop PID control to drive physical actuators.

## System Architecture
The firmware is structured into distinct functional layers to ensure modularity and real-time performance:

1.  **Measurement Layer (Sensors):** High-frequency polling of an environmental sensor suite (Ultrasonic, LDR, DHT11, Thermistor) to acquire raw "qubit" state data.
2.  **State Estimation & FSM:** A non-blocking, event-driven Finite State Machine (FSM) that processes sensor data into a unified system state vector.
3.  **Control Core (PID):** A feedback stabilization loop that computes corrective control effort based on the delta between measured state and target setpoints.
4.  **Signal Generation (Actuation):** Precise timing sequences and PWM pulse trains drive servos, stepper motors, and visual indicators to stabilize the system against injected noise.
5.  **Telemetry Readout:** Real-time data visualization via LCD1602, 7-segment displays (multiplexed via 74HC595), and a Python-based serial telemetry bridge.

## Hardware Components
*   **Microcontroller:** Arduino UNO R3 (ATmega328P)
*   **Measurement Suite:** HC-SR04 Ultrasonic, DHT11, Photoresistors, NTC Thermistor
*   **Control Actuators:** SG90 Servo, 28BYJ-48 Stepper Motor (ULN2003), Active/Passive Buzzers, 5V Relay
*   **HMI & Input:** Analog Joystick, IR Receiver, Potentiometer, Tactical Buttons
*   **Logic Expansion:** 74HC595 Shift Register (8-bit serial-to-parallel)

## Technologies Used
*   **C++ / PlatformIO:** Modular firmware architecture with strict header/source separation and hardware abstraction.
*   **Embedded Control Logic:** PID feedback loops, Finite State Machines (FSM), and non-blocking task scheduling.
*   **Python:** Host-side serial data interception and live time-series plotting (`pyserial`, `matplotlib`).
*   **Version Control:** Professional Git workflow utilizing **Conventional Commits** for structured history.

## Technical Objectives
*   **State Preparation:** Initialising the system into a stable, known configuration via calibrated sensor baselines.
*   **Disturbance Rejection:** Implementing closed-loop control to maintain system fidelity despite environmental noise (decoherence).
*   **Hardware Scaling:** Utilizing shift registers to overcome MCU pin limitations for complex multi-output multiplexing.
*   **Telemetry Pipeline:** Establishing a high-baud UART bridge (115200 bps) for real-time system analysis on macOS.

## Development Roadmap
*   **Milestone 1:** Hardware Bring-Up & Baseline Driver Validation (Current)
*   **Milestone 2:** Modular Driver Layer & Hardware Abstraction
*   **Milestone 3:** State Machine Orchestration
*   **Milestone 4:** Feedback Control Core (PID Implementation)
*   **Milestone 5:** Signal Generation & Disturbance Injection
*   **Milestone 6:** Multi-Sensor Fusion & Shift-Register Expansion
*   **Milestone 7:** Final System Validation & Python Data Logging
