#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <stdint.h>

#define ALL_LEDS_ON 0xFFFF
#define ALL_LEDS_OFF 0x0

enum Led {
    LED1 = 0,
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
    LED16
};

void ledDriverInit(uint16_t * led_address);
void ledTurnOn(uint8_t led_number);
void ledTurnOff(uint8_t led_number);
void ledsTurnAllOn();

#endif /* __LED_DRIVER_H__ */

