#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include <activity.h>
#include "unity_config.h"
#include "pico/cyw43_arch.h"

void setUp(void) {}

void tearDown(void) {}

//extern bool on;

void test_variable_assignment()
{
    sleep_ms(5000); // Give time for TTY to attach
    int x = 1;
    TEST_ASSERT_TRUE_MESSAGE(x == 1,"Variable assignment failed.");
}

void test_multiplication(void)
{
    sleep_ms(5000); // Give time for TTY to attach
    int x = 30;
    int y = 6;
    int z = x / y;
    TEST_ASSERT_TRUE_MESSAGE(z == 5, "Multiplication of two integers returned incorrect value.");
}

void activity1(void){
    sleep_ms(5000); // Give time for TTY to attach.
    char test = 'C';
    TEST_ASSERT_EQUAL_CHAR(activity('c'), test);
    printf("activity1: test passed\n");
}

void test_led_blink(void)
{
    int count = 0;
    bool on = false;

    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);

    for(int i = 0; i < 50; i++) {
        led(&on, &count);

        if (count % 11) {
            TEST_ASSERT_NOT_EQUAL(on, cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN));
        }
        else {
            TEST_ASSERT_EQUAL(on, cyw43_arch_gpio_get(CYW43_WL_GPIO_LED_PIN));
        }

    }
}

int main (void)
{
    stdio_init_all();
    hard_assert(cyw43_arch_init() == PICO_OK);
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_variable_assignment);
    RUN_TEST(test_multiplication);
    RUN_TEST(activity1);
    RUN_TEST(test_led_blink);
    sleep_ms(5000);
    return UNITY_END();
}
