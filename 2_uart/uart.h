#pragma once
#define UART0 ((NRF_UART_REG*)0x40002000) // definerer en peker til baseadressen til uart structen

void uart_init();
void uart_send(char letter);
char uart_read();