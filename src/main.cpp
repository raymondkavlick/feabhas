#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"
#include "step.h"
#include <array>
#include "pin.h"
#include "seven_segment.h"
#include "motor.h"
#include "Wash.h"
#include "WashStep.h"
#include "Rinse_step.h"
#include "Spin_step.h"
#include "SerialPort.h"
#include "Output_device.h"
#include "Scheduler.h"
#include "Thread.h"
#include "Duration.h"


int main()
{
    WMS::Motor motor{};
    Seven_segment ss{};

    FeabhOS::Scheduler::init();

    FeabhOS::Thread thread1{};
    FeabhOS::Thread thread2{};

    thread1.attach(&WMS::Motor::run, &motor);  // motor.run();
    thread2.attach(&Seven_segment::run,&ss);

    FeabhOS::Scheduler::start();

    /*
    WMS::Motor motor{};
    STM32F407::SerialPort port{};
    WMS::OutputDevice dev{};
    Seven_segment ss{};

    Step empty{Step::EMPTY,ss};
    Step fill{Step::FILL,ss};
    Step heat{Step::HEAT,ss};
    WashStep wash{ss,motor};
    RinseStep rinse{ss,motor};
    SpinStep spin{ss,motor};
    Step dry{Step::DRY,ss};
    Step comp{Step::COMPLETE,ss};

    std::array<Step *,8> step_arr_ptr
    {
        &empty,
        &fill,
        &heat,
        &wash,
        &rinse,
        &spin,
        &dry,
        &comp
    };

    Wash cycle{step_arr_ptr};
    cycle.operate();
    
    while(1);*/

}
