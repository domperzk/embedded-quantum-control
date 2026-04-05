# Hardware Wiring Map (Core Profile)

## System Constraints
*   **Serial (Reserved):** D0 (RX), D1 (TX)
*   **PWM Capable:** D3, D5, D6, D9, D10, D11
*   **Analog Input:** A0, A1, A2, A3, A4, A5

## 1. Display (LCD1602 Parallel)
*   RS: D2
*   EN: D4
*   D4: D7
*   D5: D8
*   D6: D12
*   D7: D13

## 2. Actuators & Expansion
*   Servo (SG90): D3 (PWM)
*   Shift Register Data (DS): D5
*   Shift Register Latch (STCP): D6
*   Shift Register Clock (SHCP): D9
*   *Note: Stepper Motor, LEDs, and Buzzer will be driven via the Shift Register outputs (Q0-Q7).*

## 3. Sensors (The "Quantum" Measurement Channels)
*   Ultrasonic Trigger: D10
*   Ultrasonic Echo: D11
*   DHT11 Data: A0 (Configured as Digital)
*   Thermistor: A1 (Analog)
*   Photoresistor 1: A2 (Analog)
*   Potentiometer (Target Setpoint): A3 (Analog)