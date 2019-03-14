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
    WMS::Seven_segment display{};
    WMS::Motor motor{};

    std::array<Step,10> step_arr
    {
        Step{Step::FILL},
        Step{Step::HEAT},
        Step{Step::WASH},
        Step{Step::EMPTY},
        Step{Step::FILL},
        Step{Step::RINSE},
        Step{Step::EMPTY},
        Step{Step::SPIN},
        Step{Step::DRY},
        Step{Step::COMPLETE},
    };

    std::array<Step*,10> step_arr_ptr{};

    for(int i = 0; i < 10; i++)
        step_arr_ptr[i] = &step_arr[i];

    //wash(step_arr);
    //wash_ref(step_arr_ptr);
}
