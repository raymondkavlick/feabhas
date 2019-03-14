#include "Rinse_step.h"
#include "Timer.h"

RinseStep::RinseStep(Seven_segment & ss, WMS::Motor & motor_ref) :
    Step {Step::RINSE,ss},
    motor {motor_ref}
{


}

void RinseStep::run()
{   
    Step::run();
    for(int i = 0; i < 5000;i++)
    {   
        motor.on();
        sleep(1);
        motor.off();
        sleep(1);
    }

}