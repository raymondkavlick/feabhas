#include "Peripherals.h"
#include <cstdint>
#include <array>

namespace STM32F407
{


    class Pin
    {
    public:
        explicit Pin(Peripheral::AHB1_Device port, unsigned int pin_num);
    
        void set_as_input(){    *(base_address + MODER) |= (INPUT << (num * 2));}
        void set_as_output(){   *(base_address + MODER) |= (OUTPUT << (num * 2));}
        void set(){     *(base_address + ODR) |= (1 << num);}
        void clear(){   *(base_address + ODR) &= ~(1 << num);}
        bool is_set(){  return (*(base_address + ODR) & (1 << num));}
    private:
        volatile std::uint32_t * const base_address;
        unsigned int num;

        enum offsets
        {   
            MODER = 0,
            IDR = 0x10,
            ODR = 0x14
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
