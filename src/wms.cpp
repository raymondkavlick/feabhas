#include "wms.h"
#include <cstdint>
#include "Peripherals.h"


namespace WMS
{
volatile std::uint32_t * const moder = {reinterpret_cast<std::uint32_t*>(0x40020C00)};
volatile std::uint32_t * const idr = {reinterpret_cast<std::uint32_t*>(0x40020C10)};
volatile std::uint32_t * const odr = {reinterpret_cast<std::uint32_t*>(0x40020C14)};

constexpr std::uint32_t const MOTOR{0x1000};
constexpr std::uint32_t const DIR{0x2000};

constexpr std::uint32_t const GPIO_OUT{0b10};

bool olddir = 0;


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
    *odr &= 0xF00;
}

void WMS::seg_set(unsigned int digit)
{
    *odr &= ~0xF00;
    *odr |= digit << 8;
}
