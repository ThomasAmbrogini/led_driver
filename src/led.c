#include "led.h"

static uint16_t leds = 0u;

void initLeds() {
    turnAllOff();
}

void turnOn(enum Led led) {
    uint16_t led_mask = 1 << led;
    leds |= led_mask;
}

void turnOff(enum Led led) {
    uint16_t led_mask = 0 << led;
    leds &= led_mask;
}

void turnAllOn() {
    for (int i = 0; i < LED_COUNT; ++i) {
        turnOn(i);
    }
}

void turnAllOff() {
    for (int i = 0; i < LED_COUNT; ++i) {
        turnOff(i);
    }
}

enum LedState getLedState(enum Led led) {
    enum LedState ret = INVALID;
    uint16_t retrieve_mask = 1 << led;
    ret = (leds & retrieve_mask)  >> led;

    return ret;
}

uint16_t getLeds()
{
    return leds;
}

