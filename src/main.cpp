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
    for(int i = 0; i < 10; i++)
    {
      WMS::seg_set(i);
    //std::cout << "Tick..." << std::endl;
    sleep(1000);
  }
   // WMS::motor_on();
    sleep(1000);
    WMS::motor_chg_dir();
  }


}
