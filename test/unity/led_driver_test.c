#include "unity.h"
#include "led.h"

static uint16_t virtual_leds = 0x0;

void setUp(void) {
    ledDriverInit(&virtual_leds);
}

void tearDown(void) {
}

void ledsOffAfterLedDriverInit(void) {
    uint16_t virtual_leds = 0xFFFF;
    ledDriverInit(&virtual_leds);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);
}

void turnOnLedOne(void) {
    ledTurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(0x1, virtual_leds);
}

void turnOffLedOne(void) {
    ledTurnOn(1);
    ledTurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterLedDriverInit);
    RUN_TEST(turnOnLedOne);
    RUN_TEST(turnOffLedOne);
    return UNITY_END();
}

