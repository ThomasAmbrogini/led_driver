#include <stdio.h>

#include "led.h"

int main() {
    initLeds();

    enum LedState state = getLedState(LED0);
    printf("State of the led = %d\n", state);

    turnOn(0);

    state = getLedState(LED0);
    printf("State of the led = %d\n", state);

    return 0;
}

