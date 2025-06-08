#include "logger.hpp"
#include "adc.hpp"
#include "uart.hpp"
#include "eeprom.hpp"
void Logger::printTemp() {
    int raw = adc.readTemp();
    char buffer[32];
    float tempC = ((float)raw - 673) / 1.91;
    sprintf(buffer, "Temp: %.1f C\r\n", tempC);
    uart.print(buffer);
}
void Logger::logTemp() {
    int raw = adc.readTemp();
    eeprom.writeByte(logAddress++, (raw >> 8) & 0xFF);
    eeprom.writeByte(logAddress++, raw & 0xFF);
    uart.print("Logged\r\n");
}
void Logger::readLogs() {
    uart.print("Logs:\r\n");
    for (unsigned int i = 0; i < logAddress; i += 2) {
        unsigned char hi = eeprom.readByte(i);
        unsigned char lo = eeprom.readByte(i+1);
        int raw = (hi << 8) | lo;
        float tempC = ((float)raw - 673) / 1.91;
        char buf[32];
        sprintf(buf, "%.1f C\r\n", tempC);
        uart.print(buf);
    }
}
void Logger::clearLogs() {
    logAddress = 0;
    uart.print("Logs cleared\r\n");
}
