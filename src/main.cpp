#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"


int main()
{
    WMS::gpio_init();
    WMS::motor_off();
    while(true)
    {
     // std::cout << "tick\n";
      sleep(1000);
      WMS::show_array();
    }
      // WMS::motor_on();
      sleep(1000);
      WMS::motor_chg_dir();
    
}
