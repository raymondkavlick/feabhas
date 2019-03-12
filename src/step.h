#pragma once

class Step
{
    public:
        Step() = default;
        ~Step(void);
        void set_number(int);
        void run();
    private:
        int state { 0 };
        int get_step();
};