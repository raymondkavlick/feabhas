#include "wms.h"
#include <cstdint>
#include "Peripherals.h"
#include "Timer.h"
#include <array>


namespace WMS
{
volatile std::uint32_t * const moder = {reinterpret_cast<std::uint32_t*>(0x40020C00)};
volatile std::uint32_t * const idr = {reinterpret_cast<std::uint32_t*>(0x40020C10)};
volatile std::uint32_t * const odr = {reinterpret_cast<std::uint32_t*>(0x40020C14)};

constexpr std::uint32_t const MOTOR{0x1000};
constexpr std::uint32_t const DIR{0x2000};

bool olddir = 0;
#pragma pack(1)

struct flash_object
{
    uint8_t number;
    uint8_t repeat_amount;
    uint32_t delay_between_ms;
};
#pragma pack()
static_assert(sizeof(flash_object) == 6);


std::array<flash_object,5>arr{{

flash_object{1,2,250},
flash_object{2,2,250},
flash_object{3,2,250},
flash_object{4,2,250},
flash_object{5,2,250},

}};

}


void WMS::gpio_init()
{
    STM32F407::Peripheral::enable(STM32F407::Peripheral::GPIO_D);
    *moder = 0x05550000;
}

void WMS::motor_on()
{
    *odr |= MOTOR;
}

void WMS::motor_off()
{
    *odr &= ~MOTOR;
}

void WMS::motor_chg_dir()
{
    if(olddir)
   	{
        *odr |= DIR;
        olddir = 0;
    }
    else
    {
        *odr &= ~DIR;
        olddir = 1;
    }
	
	
}

void WMS::seg_blank()
{
    *odr &= ~0xF00;
}

void WMS::seg_set(unsigned int digit)
{
    *odr &= ~0xF00;
    *odr |= digit << 8;
}

void WMS::show_array()
{
    for(auto& elem : arr)
    {
        for(auto i = 0; i < elem.repeat_amount; ++i)
        {
            seg_set(elem.number);
            sleep(elem.delay_between_ms);
            seg_blank();
            sleep(elem.delay_between_ms);
        }

    }

}
