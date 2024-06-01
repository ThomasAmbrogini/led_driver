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
    ledTurnOn(LED1);
    TEST_ASSERT_EQUAL_HEX16(0x1, virtual_leds);
}

void turnOnMultipleLeds(void) {
    ledTurnOn(LED8);
    ledTurnOn(LED9);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtual_leds);
}

void turnOnAllLeds(void) {
    ledsTurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);
}

void turnOffLedOne(void) {
    ledTurnOn(LED1);
    ledTurnOff(LED1);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);
}

void turnOffAnyLed(void) {
    ledsTurnAllOn();
    ledTurnOff(LED9);
    TEST_ASSERT_EQUAL_HEX16(0xfeff, virtual_leds);
}

void ledsHardwareNotReadable(void) {
    virtual_leds = ALL_LEDS_ON;
    ledTurnOn(LED8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtual_leds);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterLedDriverInit);
    RUN_TEST(turnOnLedOne);
    RUN_TEST(turnOnMultipleLeds);
    RUN_TEST(turnOnAllLeds);
    RUN_TEST(turnOffLedOne);
    RUN_TEST(turnOffAnyLed);
    RUN_TEST(ledsHardwareNotReadable);
    return UNITY_END();
}

