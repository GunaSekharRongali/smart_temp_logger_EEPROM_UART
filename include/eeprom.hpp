#ifndef EEPROM_HPP
#define EEPROM_HPP
class EEPROM {
public:
    void init();
    void writeByte(unsigned int addr, unsigned char data);
    unsigned char readByte(unsigned int addr);
};
extern EEPROM eeprom;
#endif