#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"





int main() {
    stdio_init_all();
    
    gpio_init(2);
    gpio_init(3);

    gpio_set_dir(2, 0);//echo brown
    gpio_set_dir(3, 1);//trig red

    if (cyw43_arch_init()) return -1;


    while (true) 
    {
            
        printf("Hello, world!\n");
        
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(100);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(100);


    }
}