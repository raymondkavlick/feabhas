#include "step.h"
#include <iostream>

void Step::set_number(int num)
{
    state = num;
}

void Step::run()
{
    std::cout << "run () - Step Number = " << state << "\n";
}

Step::~Step(void)
{
    std::cout << "Deleted!";

}