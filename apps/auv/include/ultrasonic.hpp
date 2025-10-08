#pragma once

#include "pico/stdlib.h"
#include "pico/stdlib.h"

#define US_TRIG 3
#define US_ECHO 2


absolute_time_t ping_ret_time();



bool ultrasonic_init();
