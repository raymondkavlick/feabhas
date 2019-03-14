#include "step.h"
#include <iostream>
#include "seven_segment.h"
#include "Timer.h"

void Step::set_number(step_types num)
{
    state = num;
}

void Step::run()
{
    ss.display(state);
    sleep(1000);
    //std::cout << "run () - Step Number = " << state << "\n";
}

Step::~Step(void)
{
    std::cout << "Deleted!";
}

Step::Step(step_types init_state, Seven_segment & ssref) :
    state {init_state},
    ss { ssref }
{
}
