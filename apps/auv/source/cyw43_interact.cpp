#include "cyw43_interact.hpp"
#include "pico/cyw43_arch.h"


std::int32_t cyw43_blink(std::uint32_t time_on, std::uint32_t time_off)
{
    if (cyw43_arch_init()) return -1;


    while (true) 
    {
            

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(100);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(100);


    }
}