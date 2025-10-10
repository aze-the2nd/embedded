#pragma once

#include "pico/stdlib.h"
#include "pico/stdlib.h"
#include <cstdint>

class Ultrasonic
{

    public:

// Speed of sound in cm/µs (approx. 0.0343 cm/µs)
#define SOUND_OF_SPEED 0.0343

#define US_TRIG 3
#define US_ECHO 2


double Ultrasonic::ping_ret_distance();



bool Ultrasonic::ultrasonic_init();

};