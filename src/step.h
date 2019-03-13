#pragma once

class Step
{
    public:
        explicit Step();
        explicit Step(int);
        ~Step(void);
        Step(const Step&) = delete;
        void set_number(int);
        void run() const;
        enum step_types
        {
            EMPTY = 1,
            FILL,
            HEAT,
            WASH,
            RINSE,
            SPIN,
            DRY,
            COMPLETE
        };
    private:
        int state;
        int get_step();
};