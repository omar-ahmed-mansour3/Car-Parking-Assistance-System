# Car Parking Sensor System
A real-time obstacle detection system built with the ATmega32 microcontroller to assist drivers in safe parking by providing visual and auditory alerts based on proximity.

## Key Features
*   **Precision Measurement**: Utilizes an HC-SR04 ultrasonic sensor and an Input Capture Unit (ICU) to measure distances accurately in centimeters
*   **Visual Feedback**: Displays real-time distance on a 16x2 LCD (4-bit mode) and a "Stop" warning for critical proximity
*   **Auditory Alerts**: High-priority buzzer activation when an obstacle is within 5cm
*   **Dynamic LED Logic**: Three-color LED array (Red, Green, Blue) that changes behavior based on distance ranges

## Technical Specifications
*   **Microcontroller**: ATmega32
*   **System Frequency**: 16 MHz
*   **Drivers Implemented**:
    *   **ICU Driver**: Configured with F_CPU/8 to capture rising/falling edges for pulse timing
    *   **LCD Driver**: Efficient 4-bit mode operation
    *   **Ultrasonic Driver**: Custom driver using callback functions with the ICU
    *   **Buzzer & LED Drivers**: GPIO-based control for alarm and proximity indicators.

## Operational Logic
The system applies the following feedback mapping:
*   **Distance <= 5cm**: All LEDs flashing, Buzzer ON, LCD displays "Stop".
*   **6cm - 10cm**: All LEDs (R,G,B) ON, Buzzer OFF.
*   **11cm - 15cm**: Red and Green LEDs ON, Blue OFF.
*   **16cm - 20cm**: Red LED ON only.
*   **Distance > 20cm**: All indicators OFF.

