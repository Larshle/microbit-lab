#include <stdint.h>
#include "uart.h"
#include "gpio.h"

int main(){

   gpio_init();
   uart_init();
   char A = 'A';
   char B = 'B';
   int light_on = 0;
   char letter = uart_read();

    while (1)
    {   
       
        int buttn_A(){
            return((GPIO0->IN & (1<<14)));
        }
        int buttn_B(){
            return((GPIO0->IN & (1<< 23)));
        }

        if (buttn_A() == 0){
            uart_send(A);
        }
        if (buttn_B() == 0){
            uart_send(B);
        }


        if ((light_on == 0) && ( letter != '\0'))
        {
            gpio_lights_on();
            light_on = 1;

        } else if( (light_on == 1) && (letter != '\0'))
        {
            gpio_lights_off();
            light_on = 0;
        }
        

    }
    return 0;
    
}