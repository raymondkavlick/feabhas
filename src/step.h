#pragma once
class Seven_segment;

class Step
{
    public:
        enum step_types
        {
            EMPTY = 1,
            FILL,
            HEAT,
            WASH,
            RINSE,
            SPIN,
            DRY,
            COMPLETE,
        };
        Step(step_types, Seven_segment &);
        ~Step(void);
        void set_number(step_types);
        virtual void run();
    private:
        step_types state;
        Seven_segment & ss;
        int get_step();
};