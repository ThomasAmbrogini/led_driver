#include "unity.h"
#include "led.h"
#include "runtime_error_mock.h"

static uint16_t virtual_leds = 0x0;

void setUp(void) {
    ledDriverInit(&virtual_leds);
}

void tearDown(void) {
    runtimeErrorMockReset();
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

void turnOffMultipleLeds(void) {
    ledsTurnAllOn();
    ledTurnOff(LED8);
    ledTurnOff(LED9);
    TEST_ASSERT_EQUAL_HEX16(0xFE7F, virtual_leds);
}

void turnOnAllLeds(void) {
    ledsTurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);
}

void turnOffAllLeds(void) {
    ledsTurnAllOn();
    ledsTurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);
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

void ledsBoundaryCheck(void) {
    ledTurnOn(LED16);
    ledTurnOn(LED1);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtual_leds);
}

void ledsOutOfBoundTurnOn(void) {
    ledTurnOn(-1);
    ledTurnOn(16);
    ledTurnOn(3141);
    TEST_ASSERT_EQUAL_HEX16(0x0, virtual_leds);
}

void ledsOutOfBoundTurnOff(void) {
    ledsTurnAllOn();

    ledTurnOff(-1);
    ledTurnOff(16);
    ledTurnOff(3141);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtual_leds);
}

void ledsOutOfBoundRuntimeErrorTurnOn(void) {
    ledTurnOn(-1);
    TEST_ASSERT_EQUAL_STRING("LED driver: out of bounds led",
                             runtimeErrorMockGetLastError());
    TEST_ASSERT_EQUAL_INT(-1, runtimeErrorMockGetLastParameter());
}

void ledsOutOfBoundRuntimeErrorTurnOff(void) {
    ledsTurnAllOn();
    ledTurnOff(-1);
    TEST_ASSERT_EQUAL_STRING("LED driver: out of bounds led",
                             runtimeErrorMockGetLastError());
    TEST_ASSERT_EQUAL_INT(-1, runtimeErrorMockGetLastParameter());
}

void isOn(void) {
    TEST_ASSERT_FALSE(ledIsOn(LED12));
    ledTurnOn(LED12);
    TEST_ASSERT_TRUE(ledIsOn(LED12));
}

void isOnOutOfBound(void) {
    TEST_ASSERT_FALSE(ledIsOn(-1));
    TEST_ASSERT_FALSE(ledIsOn(3439));
}

void isOff(void) {
    ledsTurnAllOn();
    TEST_ASSERT_FALSE(ledIsOff(LED12));
    ledTurnOff(LED12);
    TEST_ASSERT_TRUE(ledIsOff(LED12));
}

void todoFeature(void) {
    TEST_IGNORE();
//    TEST_IGNORE_MESSAGE("What should I do about this?");
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterLedDriverInit);
    RUN_TEST(turnOnLedOne);
    RUN_TEST(turnOnMultipleLeds);
    RUN_TEST(turnOffMultipleLeds);
    RUN_TEST(turnOnAllLeds);
    RUN_TEST(turnOffAllLeds);
    RUN_TEST(turnOffLedOne);
    RUN_TEST(turnOffAnyLed);
    RUN_TEST(ledsHardwareNotReadable);
    RUN_TEST(ledsBoundaryCheck);
    RUN_TEST(ledsOutOfBoundTurnOn);
    RUN_TEST(ledsOutOfBoundTurnOff);
    RUN_TEST(ledsOutOfBoundRuntimeErrorTurnOn);
    RUN_TEST(ledsOutOfBoundRuntimeErrorTurnOff);
    RUN_TEST(isOn);
    RUN_TEST(isOnOutOfBound);
    RUN_TEST(isOff);
    RUN_TEST(todoFeature);
    return UNITY_END();
}

