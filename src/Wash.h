
#pragma once
#include <array>
#include "step.h"

class Wash
{
    public:
        Wash(std::array<Step*,8>);
        void operate();
    private:
      std::array<Step *,8> steps;
};