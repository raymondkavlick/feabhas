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

int main()
{
    Seven_segment ss{};
    WMS::Motor motor{};

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
    
    while(1);

}
