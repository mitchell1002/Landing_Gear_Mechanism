#include <stdio.h>
#include "pico/stdlib.h"

const uint Max_REPEATS = 10; // Define the LED pin number
const int LONG_DELAY = 1000; // Define a long delay in milliseconds
const int FAST_DELAY = 25; // Define a short delay in milliseconds

int main() {

    stdio_init_all(); // Initialize all standard I/O
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
   
    printf("LED Blink Example\n");
    printf("======================\n\n");

    while (true) {
        printf("Blinking LED...\n");
        sleep_ms(LONG_DELAY); // Wait for a long delay

        printf("LED ON\n");
        gpio_put(PICO_DEFAULT_LED_PIN, true); // Turn the LED on
        sleep_ms(LONG_DELAY); // Wait for a short delay
        

        printf("LED OFF\n");
        gpio_put(PICO_DEFAULT_LED_PIN, false); // Turn the LED off
        sleep_ms(1000); // Wait for a short delay

        // Repeat the blinking process
        printf("the leb should flash on and off alot .../n");
        
        for (int repeat=0; repeat< Max_REPEATS; repeat++){

             printf("the led should flash off../n");
             gpio_put(PICO_DEFAULT_LED_PIN, true); // Turn the LED on
             sleep_ms(FAST_DELAY);

             printf("the led should flash off../n");
             gpio_put(PICO_DEFAULT_LED_PIN, false); // Turn the LED on
             sleep_ms(FAST_DELAY);


        }
       
    }  
   
    
}
