#pragma once
#include "step.h"
#include "motor.h"
#include "Rinse_step.h"

class RinseStep : public Step
{
    public:
        RinseStep(Seven_segment&,WMS::Motor &);
        void run() override;

    private:
        WMS::Motor & motor;
};
