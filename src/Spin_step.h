#pragma once
#include "step.h"
#include "motor.h"

class SpinStep : public Step
{
    public:
        SpinStep(Seven_segment&,WMS::Motor &);
        void run() override;

    private:
        WMS::Motor & motor;
};