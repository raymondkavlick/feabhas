#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"
#include "step.h"
#include <array>
#include "pin.h"



int main()
{
    STM32F407::Pin led1{STM32F407::Peripheral::GPIO_D,12};
    STM32F407::Pin led2{STM32F407::Peripheral::GPIO_D,11};
    STM32F407::Pin led3{STM32F407::Peripheral::GPIO_D,10};
    STM32F407::Pin led4{STM32F407::Peripheral::GPIO_D,9};

    led1.set_as_output();
    led2.set_as_output();
    led3.set_as_output();
    led4.set_as_output();

    led1.set();
    led2.set();
    led3.set();
    led4.set();

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

void wash_ref(const std::array<Step*,10> & arr)
{
    for(auto &elem : arr)
        elem->run();
}