#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "activity.h"


char activity(char c) {

    if (c <= 'z' && c >= 'a') return (c - 32);
    else if (c >= 'A' && c <= 'Z') return (c + 32);
    else return (c);

}