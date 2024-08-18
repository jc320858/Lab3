/**************************************************************
 * main.c
 * rev 1.0 18-Aug-2024 owner
 * Lab3
 * ***********************************************************/

#include "pico/stdlib.h"
#include <stdbool.h>
#include <stdio.h>  

int main(void)
{ 
    stdio_init_all(); // Initialise all of the present standard stdio types that are linked into the binary
    // Initialise the GPIO pin that controls the on-board LED 
   
    const int red_PIN = 11 ;
    const int green_PIN = 12;
    const int blue_PIN = 13; 
    

    // uart_init(UART_ID, BAUD_RATE);
    
    // Set TX and RX 
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART); 
 
    // Set GPIO as outputs 
    gpio_init(red_PIN);
    gpio_set_dir(red_PIN, GPIO_OUT);

    gpio_init(green_PIN);
    gpio_set_dir(green_PIN, GPIO_OUT); 

    gpio_init(blue_PIN);
    gpio_set_dir(blue_PIN, GPIO_OUT);

    // Loop for ever
    while (true) {
        int ch = getchar_timeout_us(0);
        if (ch != PICO_ERROR_TIMEOUT){
            // Checks input

            switch (ch) { 
                case 'r': 
                if (gpio_get(red_PIN) == 0) {
                    gpio_put(red_PIN, 1); // Switch on the LED 
                    printf("Red LED is on\n");
                } else {
                    gpio_put(red_PIN, 0); // Switch off the LED
                    printf("Red LED is off\n");
                }

                break;

                case 'g': 
                    if (gpio_get(green_PIN) == 0){ // Switch on the LED 
                    gpio_put(green_PIN, 1); // Switch on the LED
                    printf("Green LED is on\n");
                } else {    
                    gpio_put(green_PIN, 0); // Switch off the LED
                    printf("Green LED is off\n");  
                }     
                    break;
                
                case 'b': 
                    if (gpio_get(blue_PIN) == 0){ // Switch on the LED 
                    gpio_put(blue_PIN, 1); // Switch on the LED
                    printf("Blue LED is on\n");
                } else {    
                    gpio_put(blue_PIN, 0); // Switch off the LED
                    printf("Blue LED is off\n");   
                }
                    break;  
            }
        }
    }
}
