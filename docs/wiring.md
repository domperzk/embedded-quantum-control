# Hardware Wiring Map (v2.0 - Shift Register Architecture)

## System Constraints
* **Available IO:** D2-D13, A0-A5 (Fully Allocated)
* **Reserved:** D0 (RX), D1 (TX)

## 1. The Core Bottleneck (74HC595 Shift Register)
This chip handles all non-timing-critical outputs to save MCU pins.
* **Arduino D11** -> Pin 14 (DS / Data)
* **Arduino D8** -> Pin 12 (STCP / Latch)
* **Arduino D12** -> Pin 11 (SHCP / Clock)
* **Arduino 5V** -> Breadboard positive power rail
* **Arduino GND** -> Breadboard ground rail

**Shift Register Outputs (Q0 - Q7):**
* `Q0` (Pin 15) -> Status LED (with 220Ω resistor)
* `Q1` (Pin 1)  -> Active Buzzer Signal
* `Q2` (Pin 2)  -> Reserved (RGB / extra LED)
* `Q3` (Pin 3)  -> Reserved (RGB / extra LED)
* `Q4` (Pin 4)  -> ULN2003 IN1 (Stepper)
* `Q5` (Pin 5)  -> ULN2003 IN2 (Stepper)
* `Q6` (Pin 6)  -> ULN2003 IN3 (Stepper)
* `Q7` (Pin 7)  -> ULN2003 IN4 (Stepper)

## 2. Display (LCD1602 Parallel)
* **D2** -> RS
* **D4** -> EN
* **D5** -> D4
* **D6** -> D5
* **D7** -> D6
* **D13** -> D7

## 3. High-Speed Actuator
* **D3** -> Servo Motor (SG90) Control Line (PWM required)

## 4. Sensors (The Measurement Channels)
* **D9** -> Ultrasonic Trigger
* **D10** -> Ultrasonic Echo
* **A0** -> DHT11 Data
* **A1** -> Thermistor (via voltage divider)
* **A2** -> Photoresistor (via voltage divider)

## 5. Input (Command & Control)
* **A3** -> Potentiometer Wiper (System Target Setpoint)
* **A4** -> Joystick VRx
* **A5** -> Joystick VRy
*(Note: Joystick SW button is dropped due to pin constraints. Joystick axis movement will handle mode switching).*