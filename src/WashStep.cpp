#include "WashStep.h"
#include "Timer.h"

WashStep::WashStep(Seven_segment & ss, WMS::Motor & motor_ref) :
    Step {Step::WASH,ss},
    motor {motor_ref}
{


}

void WashStep::run()
{
    Step::run();
    motor.on();
    sleep(3000);
    motor.change_direction();
    sleep(3000);
    motor.off();

}