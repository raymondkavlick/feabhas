#include "step.h"
#include <iostream>

void Step::set_number(int num)
{
    state = num;
}

void Step::run() const
{
    std::cout << "run () - Step Number = " << state << "\n";
}

Step::~Step(void)
{
    std::cout << "Deleted!";
}

Step::Step(int init_state)
{
    state = init_state;
    std::cout << "Init. State = " << init_state << std::endl;
}

Step::Step()
{
    std::cout << "Default Const. called.\n";
}