#include "led.h"

uint16_t * leds_address;

void ledDriverInit(uint16_t * address) {
    leds_address = address;
    *leds_address = 0;
}

void ledTurnOn(uint8_t led_number) {
    *leds_address = 1;
}

void ledTurnOff(uint8_t led_number) {
    *leds_address = 0;
}

