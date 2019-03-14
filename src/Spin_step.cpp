#include "Spin_step.h"
#include "Timer.h"

SpinStep::SpinStep(Seven_segment & ss, WMS::Motor & motor_ref) :
    Step {Step::SPIN,ss},
    motor {motor_ref}
{


}

void SpinStep::run()
{
    Step::run();
        motor.on();
        sleep(6000);
        motor.off();

}