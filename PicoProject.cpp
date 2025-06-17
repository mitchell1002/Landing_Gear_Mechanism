#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN PICO_DEFAULT_LED_PIN
#define BUTTON_PIN 15 // Change this to your actual button GPIO pin

const uint MAX_REPEATS = 10;
const int LONG_DELAY = 1000; // milliseconds
const int FAST_DELAY = 25;   // milliseconds

int main() {
    stdio_init_all();

    // Initialize LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Initialize button pin with pull-up resistor
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    printf("Pico LED Button Blink Example\n");
    printf("=============================\n");

    bool wasPressed = false;

    // Turn LED ON by default
    gpio_put(LED_PIN, true);

    while (true) {
        bool buttonPressed = (gpio_get(BUTTON_PIN) == 0); // LOW means pressed

        if (buttonPressed) {
            if (!wasPressed) {
                printf("Button pressed. Starting to blink LED...\n");
                wasPressed = true;
            }
            // Blink LED repeatedly
            for (uint repeat = 0; repeat < MAX_REPEATS; repeat++) {
                gpio_put(LED_PIN, false);
                sleep_ms(FAST_DELAY);
                gpio_put(LED_PIN, true);
                sleep_ms(FAST_DELAY);
            }
        } else {
            if (wasPressed) {
                printf("Button released. LED stays ON.\n");
                wasPressed = false;
            }
            gpio_put(LED_PIN, true); // Keep LED ON when button not pressed
            sleep_ms(LONG_DELAY);    // Slow down loop to avoid flooding serial output
        }
    }
}
