#include "eeprom.h"
#include <msp430.h>

#define EEPROM_I2C_ADDRESS 0x50
#define LOG_START_ADDRESS  0x00
#define MAX_LOGS           100
#define EEPROM_PAGE_SIZE   16

EEPROM::EEPROM(I2CInterface& i2cRef) : i2c(i2cRef), logIndex(0) {}

void EEPROM::init() {
    i2c.init();
    logIndex = 0;
}

void EEPROM::writeByte(unsigned int addr, uint8_t data) {
    i2c.start();
    i2c.send(EEPROM_I2C_ADDRESS << 1); // Write mode
    i2c.send((addr >> 8) & 0xFF);      // High byte of address
    i2c.send(addr & 0xFF);             // Low byte
    i2c.send(data);                    // Data byte
    i2c.stop();
    __delay_cycles(5000);             // EEPROM write delay
}

uint8_t EEPROM::readByte(unsigned int addr) {
    i2c.start();
    i2c.send(EEPROM_I2C_ADDRESS << 1); // Write mode to send address
    i2c.send((addr >> 8) & 0xFF);
    i2c.send(addr & 0xFF);
    i2c.start();                       // Repeated START
    i2c.send((EEPROM_I2C_ADDRESS << 1) | 1); // Read mode
    uint8_t data = i2c.recv(false);    // Read 1 byte, then NACK
    i2c.stop();
    return data;
}
