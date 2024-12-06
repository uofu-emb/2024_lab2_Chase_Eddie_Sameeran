#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include <activity.h>
#include "unity_config.h"

void setUp(void) {}

void tearDown(void) {}

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


int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_variable_assignment);
    RUN_TEST(test_multiplication);
    RUN_TEST(activity1);
    sleep_ms(5000);
    return UNITY_END();
}
