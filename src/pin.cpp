#include "pin.h"

namespace STM32F407
{
    Pin::Pin(Peripheral::AHB1_Device port, unsigned int pin_num) :
        base_address {reinterpret_cast<std::uint32_t*>(base_arr[port])},
        num {pin_num}
    {   
        Peripheral::enable(port);
    }

}


