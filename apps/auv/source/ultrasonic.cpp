#include "ultrasonic.hpp"


class Ultrasonic
{

private:
    /* data */

    static absolute_time_t time_echo_start;
    static absolute_time_t time_echo_end;

public:
    Ultrasonic(/* args */);


    ~Ultrasonic() = default;


Ultrasonic::Ultrasonic(/* args */)
{
}

Ultrasonic::~Ultrasonic()
{

}



static absolute_time_t absolute_time_diff_us (const absolute_time_t t, uint32_t ms);


bool Ultrasonic::ultrasonic_init()
{

    gpio_init(US_ECHO);
    gpio_init(US_TRIG);

    gpio_set_dir(US_ECHO, false);//echo brown
    gpio_set_dir(US_TRIG, true);//trig red

    

    return false;
}

double Ultrasonic::ping_ret_distance()
{

    static double distance_cm = 0;


    gpio_put(US_TRIG, false);
    sleep_us(2);

    gpio_put(US_TRIG, true);
    sleep_us(10);
    gpio_put(US_TRIG, false);

    while (gpio_get(US_ECHO == 0))
    {
        time_echo_start = get_absolute_time();
    }

    while (gpio_get(US_ECHO == 1))
    {
        time_echo_end = get_absolute_time();
    }

    std::int64_t time_echo_pulse = absolute_time_diff_us(time_echo_start, time_echo_end);

    distance_cm = (time_echo_pulse * SOUND_OF_SPEED);

    return distance_cm;
}

};