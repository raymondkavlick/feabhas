#pragma once
#include "step.h"
#include "motor.h"

class WashStep : public Step
{
    public:
        WashStep(Seven_segment&,WMS::Motor &);
        void run() override;

    private:
        WMS::Motor & motor;
};