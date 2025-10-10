#include <stdio.h>
#include "pico/stdlib.h"
#include "ultrasonic.hpp"

//https://www.youtube.com/watch?v=jnC5LrTx470








int main() {
    
    stdio_init_all();

    //Ultrasonic::ultrasonic_init();
    auto us = Ultrasonic();

    Ultrasonic::ultrasonic_init();

    while (true)
    {

    }
    

}

