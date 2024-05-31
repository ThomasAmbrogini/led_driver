#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <stdint.h>

void ledDriverInit(uint16_t * led_address);
void ledTurnOn(uint8_t led_number);
void ledTurnOff(uint8_t led_number);

#endif /* __LED_DRIVER_H__ */

