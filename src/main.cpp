#include <msp430.h>
#include "adc.hpp"
#include "uart.hpp"
#include "eeprom.hpp"
#include "logger.hpp"

Logger logger;

void main() {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    uart.init();     // Initialize UART
    adc.init();      // Initialize ADC for temperature
    eeprom.init();   // Initialize EEPROM (I2C)

    uart.print("\r\nMSP430 Temp Logger Ready\r\n");

    while (1) {
        if (uart.available()) {
            char cmd = uart.read();
            switch (cmd) {
                case 't':
                    logger.printTemp();
                    break;
                case 'l':
                    logger.logTemp();
                    break;
                case 'r':
                    logger.readLogs();
                    break;
                case 'c':
                    logger.clearLogs();
                    break;
                default:
                    uart.print("Unknown command\r\n");
            }
        }
    }
}
