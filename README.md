# PC-Based Data Acquisition System with Fault Alerts

## 📌 Project Overview

This project is developed using the LPC2148 ARM7 Microcontroller to continuously monitor temperature using the LM35 sensor.  
The system records temperature data along with real-time timestamps using the RTC (Real-Time Clock) and sends the information to a PC through UART communication.

Whenever the temperature exceeds a predefined threshold value, the system generates a fault alert using LED/Buzzer and also sends alert messages to the serial terminal.

The project also supports RTC time editing using a keypad triggered through external interrupt.

---

# 🚀 Features

- Real-time temperature monitoring
- RTC-based timestamp logging
- UART communication with PC
- Serial terminal data monitoring
- Over-temperature fault alert
- LCD live display
- Keypad-based RTC editing
- External interrupt handling
- Embedded C implementation

---

# 🛠️ Hardware Requirements

- LPC2148 Microcontroller
- LM35 Temperature Sensor
- 16x2 LCD
- Keypad
- Push Button
- LED / Buzzer
- MAX232
- Power Supply

---

# 💻 Software Requirements

- Embedded C
- Keil uVision
- Flash Magic
- Serial Terminal (PuTTY / TeraTerm)
# ⚙️ System Working

## 1. System Initialization

After power ON, LPC2148 initializes:

- UART communication
- RTC module
- ADC for LM35
- LCD display
- Keypad
- LED/Buzzer
- External interrupt

---

## 2. Temperature Monitoring

The ADC continuously reads analog data from the LM35 sensor and converts it into temperature values.

Example:

```text
Temperature = 32.5°C


---
# Author
Badam Harish


