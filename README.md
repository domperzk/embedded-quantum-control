# Embedded Quantum Control Platform

💡 **What is this?**

This project is a step up from basic hardware sketches. It is a **modular, real-time embedded control and signal processing platform** built around an Arduino UNO R3. 

The goal isn't to build a pretend quantum computer, but to map real "quantum control" concepts (like state preparation, pulse sequences, and decoherence) onto standard embedded systems architecture (like finite state machines, PWM control, and PID feedback loops). It ingests multiple sensor inputs, processes them into a unified system state, applies control logic, and drives physical actuators while exporting live telemetry.

🛠️ **How it works**

*   **The Sensors (Measurement):** Photoresistors, a thermistor, DHT11, and an ultrasonic sensor act as our measurement channels, picking up environmental data and injecting "noise" (disturbances).
*   **The Brain (State Estimation & FSM):** A non-blocking, event-driven Finite State Machine (FSM) takes user inputs and sensor data, compares it to a target state, and calculates the necessary control effort.
*   **The Actuators (Control Output):** Servos, stepper motors, LEDs, and buzzers fire off precise timing patterns (PWM pulse sequences) to actively correct the system state and visually demonstrate the control loops in action.
*   **The Telemetry (Readout):** An LCD1602, 7-segment displays (driven by a 74HC595 shift register), and a live Python serial bridge show exactly what the system is doing, tracking target vs. actual values in real-time.

🧱 **Parts List**

*   **Core:** Arduino UNO R3
*   **Inputs:** Ultrasonic Sensor, DHT11 (Temp/Humidity), Joystick, IR Receiver, Potentiometer, Tilt Switch, Buttons, Photoresistors, Thermistor.
*   **Outputs:** Servo Motor (SG90), Stepper Motor + ULN2003 Driver, Active/Passive Buzzers, LEDs (RGB, Yellow, Blue, Green, Red), LCD1602, 1-digit & 4-digit 7-segment displays.
*   **Electronics:** 74HC595 Shift Register, 5V Relay, PN2222 Transistors, 1N4007 Diodes, Resistors, Breadboard.

💻 **Tech Stack**

*   **C++ / PlatformIO:** For a modular, multi-file embedded architecture (separating headers and source files).
*   **Python:** For the host-side serial data bridge and plotting the response curves (Matplotlib).
*   **Git / GitHub:** Version control using the Conventional Commits specification.

🚀 **Development Phases**

This project is being built in structured engineering milestones:
1.  **Phase 1:** Hardware Bring-Up and Baseline Drivers
2.  **Phase 2:** Modular Driver Layer (Hardware Abstraction)
3.  **Phase 3:** State Machine and System Orchestration
4.  **Phase 4:** Feedback Control Core (PID Implementation)
5.  **Phase 5:** Signal Generation and Disturbance Injection
6.  **Phase 6:** Multi-Sensor Fusion and Shift-Register Integration
7.  **Phase 7:** Python Data Logging and System Validation