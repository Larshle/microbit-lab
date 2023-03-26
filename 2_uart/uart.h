#pragma once
#include <stdint.h>
#define UART0 ((NRF_UART_REG*)0x40002000) // definerer en peker til baseadressen til uart structen
#define UART0 ((NRF_UART_REG*)0x40002000)
typedef struct 
{
    volatile uint32_t TASKS_STARTRX;
    volatile uint32_t TASKS_STOPRX;
    volatile uint32_t TASKS_STARTTX;
    volatile uint32_t TASKS_STOPTX;
    volatile uint32_t RESRESERVED0[3];
    volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESRESERVED1[56];
    volatile uint32_t EVENTS_CTS;
    volatile uint32_t EVENTS_NCTS;
    volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESRESERVED2[4];
    volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESRESERVED3[1];
    volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESRESERVED4[7];
    volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESRESERVED5[46];
    volatile uint32_t SHORTS;
    volatile uint32_t RESRESERVED6[64];
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;
    volatile uint32_t RESRESERVED7[93];
    volatile uint32_t ERRORSRC;
    volatile uint32_t RESRESERVED8[31];
    volatile uint32_t ENABLE;
    volatile uint32_t RESRESERVED9[1];
    volatile uint32_t PSEL_RTS;
    volatile uint32_t PSEL_TXD;
    volatile uint32_t PSEL_CTS;
    volatile uint32_t PSEL_RXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;
    volatile uint32_t RESRESERVED10[1];
    volatile uint32_t BAUDRATE;
    volatile uint32_t RESRESERVED11[21];
    volatile uint32_t CONFIG;

} NRF_UART_REG;

void uart_init();
void uart_send(char letter);
char uart_read();