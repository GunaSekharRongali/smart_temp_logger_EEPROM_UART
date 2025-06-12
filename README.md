# MSP430 Temperature Logger (EEPROM + UART Interface)

This project demonstrates a modular, object-oriented embedded system designed to read temperature data using the ADC of the MSP430, log it into EEPROM, and communicate via UART. The system supports command-based interaction to **read temperature**, **log data**, **view logs**, and **clear logs** through a UART terminal.

## 🔧 Hardware Used

- **Microcontroller**: MSP430G2553 or compatible
- **Sensor**: Internal temperature sensor (via ADC)
- **Interfaces**:
  - UART (for PC communication)
  - I2C EEPROM (for persistent storage)

## 🧠 Features

- Modular C++ code using separate classes for ADC, EEPROM, UART, and Logging logic
- UART command interface:
  - `t` – Show current temperature
  - `l` – Log current temperature to EEPROM
  - `r` – Read and display all logged entries
  - `c` – Clear EEPROM log
- ADC-based internal temperature reading
- EEPROM byte-wise memory management
- UART-based terminal feedback
