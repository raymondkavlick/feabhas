#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"
#include "step.h"

int main()
{
    Step fill {};
    Step wash {};
    Step empty {};

    fill.set_number(2);
    wash.set_number(4);
    empty.set_number(1);

    fill.run();
    wash.run();
    empty.run();

}
