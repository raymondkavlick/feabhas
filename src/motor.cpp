

#include "motor.h"
#include "pin.h"
#include "Scheduler.h"
#include "Thread.h"
#include "Duration.h"

#include "Scheduler.h"
#include "Thread.h"
#include <iostream>
#include "Duration.h"
using namespace FeabhOS::Time;
namespace WMS{

Motor::Motor()
{
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

void Motor::run()
{
    while(1)
    {
        
        FeabhOS::Thread::sleep(500_ms);
        std::cout << "Motor!\r\n";
    }
}

}