#ifndef UART_HPP
#define UART_HPP
class UART {
public:
    void init();
    void print(const char* str);
    bool available();
    char read();
};
extern UART uart;
#endif