#pragma once

#include "Peripherals.h"
#include <cstdint>
#include <array>

namespace STM32F407
{


    class Pin
    {
    public:
        explicit Pin(Peripheral::AHB1_Device port, unsigned int pin_num);
    
        void set_as_input();
        void set_as_output();
        void set();
        void clear();
        bool is_set();
    private:
        volatile std::uint32_t * const base_address;
        unsigned int num;

        enum offsets
        {   
            MODER = 0,
            IDR = 4,
            ODR = 5
        };


        enum port_settings
        {
            INPUT = 0b00,
            OUTPUT = 0b01,
            ALT = 0b10,
            ANALOG = 0b11,
        };

        static constexpr std::array<std::uint32_t, 9> base_arr = 
        {
            0x40020000,
            0x40020400,
            0x40020800,
            0x40020C00,
            0x40021000,
            0x40021400,
            0x40021800,
            0x40021C00,
            0x40022000,
        };
    
    };
}
