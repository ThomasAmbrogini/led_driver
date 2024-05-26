#include "unity.h"
#include "led.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void ledsOffAfterInit(void) {
    turnAllOn();
    initLeds();
    uint16_t leds = getLeds();
    TEST_ASSERT_EQUAL_HEX16(0, leds);
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(ledsOffAfterInit);
    return UNITY_END();
}

