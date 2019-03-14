#include "pin.h"
#include <iostream>

namespace STM32F407
{
    Pin::Pin(Peripheral::AHB1_Device port, unsigned int pin_num) :
        base_address {reinterpret_cast<std::uint32_t*>(base_arr[port])},
        num {pin_num}
    {   
        Peripheral::enable(port);
        set_as_output();
        clear();
    }

    void Pin::set_as_input()
    {    
        *(base_address + MODER) |= (INPUT << (num * 2));
    }

    void Pin::set_as_output()
    {  
        *(base_address + MODER) |= (OUTPUT << (num * 2));
    };

    void Pin::set()
    {   
        *(base_address + ODR) |= (1 << num);
    };

    void Pin::clear()
    {  
        *(base_address + ODR) &= ~(1 << num);
    };

    bool Pin::is_set(){  return (*(base_address + ODR) & (1 << num));};
    

}


