#include <iostream>
#include <cstdint>
#include "Timer.h"
#include "wms.h"
#include "step.h"

int main()
{
    Step fill{};
    Step wash{4};
    Step empty{1};

    fill.set_number(2);
    wash.set_number(4);
    empty.set_number(1);

    fill.run();
    wash.run();
    empty.run();

}
