#pragma once
#include <stdint.h>

#define UART0 ((NRF_UART_REG*)0x40002000) // definerer en peker til baseadressen til uart structen
#define UART1 ()
void uart_init();
void uart_send(char letter);
char uart_read();