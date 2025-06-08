#include <msp430.h>
#include "uart.hpp"
UART uart;
void UART::init() {
    P1SEL |= BIT1 + BIT2; P1SEL2 |= BIT1 + BIT2;
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 = 104;  UCA0BR1 = 0;
    UCA0MCTL = UCBRS0;
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
}
void UART::print(const char* str) {
    while (*str) {
        while (!(IFG2 & UCA0TXIFG));
        UCA0TXBUF = *str++;
    }
}
bool UART::available() {
    return IFG2 & UCA0RXIFG;
}
char UART::read() {
    return UCA0RXBUF;
}