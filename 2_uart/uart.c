#include "uart.h"
#include "gpio.h"



void uart_init(){ //inisialliserer UART
    GPIO1 -> PIN_CNF[8] = 1;  // setter TX pinnen til output
    GPIO0 -> PIN_CNF[6] = 0;  // setter RX pinnen til innput
    
    UART0 -> PSEL_TXD = 8; // setter riktig pin til UART modulen, "mappes" pin til uart registre
    UART0 -> PSEL_RXD = 6; 

    UART0 -> BAUDRATE = 0x00275000; // setter baudrate/bits per s til 9600 fordi vi ikke har no CTS eller RTS pins
    
    UART0 -> PSEL_CTS = 0xFFFFFFFF; //setter alle pins til 1 på CTS og RTS for å si til UART at vi ikke har noe CTS eller RTS
    UART0 -> PSEL_RTS = 0xFFFFFFFF;

    UART0 -> ENABLE = 0x4; //enable her skrur på UART modulen

    UART0 -> TASKS_STARTRX = 0x1; //starter UART reciver
    
}

void uart_send(char letter){ // sender bokstav til PC
    UART0 -> TASKS_STARTTX = 0x1;  // starter transsmisjonen

    UART0 -> TXD = letter; // sender char letteret til riktig register

    while (!UART0->EVENTS_TXDRDY); // sjekker om flagget er satt, om det ikke er satt er EVENTS_TXDRDy satt til 0 og whilen blir en og kjører, når den TXD registret er tomt blir det satt til en og klar til å sende
    
    UART0 -> TASKS_STOPTX = 0x1; //stopper transmisjonen

}

char uart_read(){
    UART0 -> TASKS_STARTRX = 0x1;  // starter lesing av registeret
    
    while (!UART0->EVENTS_RXDRDY){ // flagget blir satt til 1 så går den ut av loopen og leser dataen 
        return "\0";
    }
   
    char letter = UART0 -> RXD;

    UART0 -> EVENTS_RXDRDY = 0;

    return letter;
}
