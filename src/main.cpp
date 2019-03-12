#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"



int main()
{
  WMS::gpio_init();
  WMS::motor_on();
  while(true)
  {
    //std::cout << "Tick..." << std::endl;
    sleep(1000);
   // WMS::motor_on();
    sleep(1000);
    WMS::motor_chg_dir();
  }


}
