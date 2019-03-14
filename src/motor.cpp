

#include "motor.h"
#include "pin.h"

namespace WMS{

Motor::Motor()
{
    //STM32F407::Pin motor_control_pin{STM32F407::Peripheral::GPIO_D,12};
    //STM32F407::Pin motor_dir_pin{STM32F407::Peripheral::GPIO_D,13};
    off();
}

Motor::~Motor()
{
    off();
}
void Motor::on()
{
    motor_control_pin.set();

}
void Motor::off()
{
    motor_control_pin.clear();
}
void Motor::change_direction()
{
    if(motor_dir_pin.is_set())
        motor_dir_pin.clear();
    else
        motor_dir_pin.set();
    
}

}