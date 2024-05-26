#ifndef __TDD_LED_H__
#define __TDD_LED_H__

#include <stdint.h>

enum Led {
    LED0,
    LED1,
    LED2,
    LED3,
    LED4,
    LED5,
    LED6,
    LED7,
    LED8,
    LED9,
    LED10,
    LED11,
    LED12,
    LED13,
    LED14,
    LED15,
    LED_COUNT
};

enum LedState {
    OFF,
    ON,
    INVALID
};

/* Turns all the led on */
void initLeds();

void turnOn(enum Led led);
void turnOff(enum Led led);

void turnAllOn();
void turnAllOff();

uint16_t getLeds();

enum LedState getLedState(enum Led led);

#endif /* __TDD_LED_H__ */

