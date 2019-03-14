#pragma once
#include "Peripherals.h"
#include "pin.h"

class Seven_segment
{
    public:
        Seven_segment();
        ~Seven_segment();

        void display(unsigned int val);
        void blank();
    private:
        STM32F407::Pin led6{STM32F407::Peripheral::GPIO_D,8};
        STM32F407::Pin led5{STM32F407::Peripheral::GPIO_D,9};
        STM32F407::Pin led4{STM32F407::Peripheral::GPIO_D,10};
        STM32F407::Pin led3{STM32F407::Peripheral::GPIO_D,11};
};