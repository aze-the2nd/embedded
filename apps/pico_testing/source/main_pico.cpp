#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"




void second_core_code()
{

    while (true)
    {
        sleep_ms(500);
        multicore_fifo_push_blocking(true);
        sleep_ms(500);
        multicore_fifo_push_blocking(false);

    }
}


int main() 
{


    if (cyw43_arch_init()) return -1;
    stdio_init_all();

    multicore_launch_core1(second_core_code);

    while(true)
    {
        uint32_t command = multicore_fifo_pop_blocking();

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, command);
        
    }

/*
*/
    
    gpio_init(2);
    gpio_init(3);

    gpio_set_dir(2, 0);//echo brown
    gpio_set_dir(3, 1);//trig red



    while (true) 
    {
            
        printf("Hello, world!\n");

        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(100);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(100);


    }

}

