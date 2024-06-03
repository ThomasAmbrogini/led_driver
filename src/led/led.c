#include "led.h"

#include "runtime_error.h"

uint16_t * leds_address;
uint16_t leds_image;

void ledDriverInit(uint16_t * address) {
    leds_address = address;
    leds_image = ALL_LEDS_OFF;
    *leds_address = leds_image;
}

void ledTurnOn(uint8_t led_number) {
    if ((led_number >= LED1) && (led_number <= LED16)) {
        leds_image |= (1 << led_number);
        *leds_address = leds_image;
    }
    else {
        RUNTIME_ERROR("LED driver: out of bounds led", led_number);
    }
}

void ledTurnOff(uint8_t led_number) {
    if ((led_number >= LED1) && (led_number <= LED16)) {
        uint16_t led_select_mask = 1 << led_number;
        leds_image &= ~led_select_mask;
        *leds_address = leds_image;
    }
}

void ledsTurnAllOn() {
    leds_image = ALL_LEDS_ON;
    *leds_address = leds_image;
}

