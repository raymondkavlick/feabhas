#pragma once

class Step
{
    public:
        Step();
        Step(int);
        ~Step(void);
        void set_number(int);
        void run();
    private:
        int state;
        int get_step();
};