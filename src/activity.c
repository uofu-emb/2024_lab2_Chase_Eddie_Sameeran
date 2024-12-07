#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "activity.h"

char activity(char c) {

    if (c <= 'z' && c >= 'a') return (c - 32);
    else if (c >= 'A' && c <= 'Z') return (c + 32);
    else return (c);

}

void led(bool *on, int *count) {
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, *on);
    *count += 1;
    if (*count % 11) {
        *on = !*on;
    }
}