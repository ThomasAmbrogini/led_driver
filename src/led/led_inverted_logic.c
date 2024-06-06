#include "led.h"

#include "runtime_error.h"

uint16_t * leds_address;
uint16_t leds_image;

static enum LedLogic logic_type;

static uint8_t isLedOutOfBound(enum Led led_number);

uint16_t getLedValues(void) {
    uint16_t ret = 0u;
    
    if (logic_type == REGULAR) {
        ret = leds_image;
    }
    else {
        ret = ~leds_image;
    }

    return ret;
}

void ledDriverInit(uint16_t * address, enum LedLogic _logic_type) {
    leds_address = address;
    logic_type = _logic_type;

    if (logic_type == REGULAR)
    {
        leds_image = ALL_LEDS_OFF;
    }
    else {
        leds_image = ALL_LEDS_ON;
    }

    *leds_address = leds_image;
}

void ledTurnOn(enum Led led_number) {
    if (!isLedOutOfBound(led_number)) {
        if (logic_type == REGULAR) {
            leds_image |= (1 << led_number);
        }
        else {
            leds_image = ~leds_image | (1 << led_number);
            leds_image = ~leds_image;
        }
        *leds_address = leds_image;
    }
    else {
        RUNTIME_ERROR("LED driver: out of bounds led", led_number);
    }
}

void ledTurnOff(enum Led led_number) {
    if (!isLedOutOfBound(led_number)) {
        uint16_t led_select_mask = 1 << led_number;
        if (logic_type == REGULAR) {
            leds_image &= ~led_select_mask;
        }
        else {
            leds_image = ~leds_image & ~led_select_mask;
            leds_image = ~leds_image;
        }
        *leds_address = leds_image;
    }
    else {
        RUNTIME_ERROR("LED driver: out of bounds led", led_number);
    }
}

void ledsTurnAllOn() {
    if (logic_type == REGULAR) {
        leds_image = ALL_LEDS_ON;
    }
    else {
        leds_image = ALL_LEDS_OFF;
    }

    *leds_address = leds_image;
}

void ledsTurnAllOff() {
    if (logic_type == REGULAR) {
        leds_image = ALL_LEDS_OFF;
    }
    else {
        leds_image = ALL_LEDS_ON;
    }
    *leds_address = leds_image;
}

uint8_t ledIsOn(enum Led led_number) {
    uint8_t ret = 0u;

    if (!isLedOutOfBound(led_number)) {
        if (logic_type == REGULAR) {
            ret = !!(leds_image & (1 << led_number));
        }
        else {
            ret = !!(~leds_image & (1 << led_number));
        }
    }

    return ret;
}

uint8_t ledIsOff(enum Led led_number) {
    return !ledIsOn(led_number);
}

static uint8_t isLedOutOfBound(enum Led led_number) {
    uint8_t ret = 0u;

    if ((led_number < LED1) || (led_number > LED16)) {
        ret = 1u;
    }

    return ret;
}

