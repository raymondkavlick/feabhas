#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"
#include "step.h"
#include <array>
#include "pin.h"
#include "seven_segment.h"
#include "motor.h"

int main()
{
    Seven_segment ss{};
    WMS::Motor motor{};

    std::array<Step,10> step_arr
    {
        Step{Step::FILL,ss},
        Step{Step::HEAT,ss},
        Step{Step::WASH,ss},
        Step{Step::EMPTY,ss},
        Step{Step::FILL,ss},
        Step{Step::RINSE,ss},
        Step{Step::EMPTY,ss},
        Step{Step::SPIN,ss},
        Step{Step::DRY,ss},
        Step{Step::COMPLETE,ss},
    };

    std::array<Step*,10> step_arr_ptr{};

    for(int i = 0; i < 10; i++)
        step_arr_ptr[i] = &step_arr[i];

    for(auto &elem : step_arr_ptr)
        elem->run();

}
