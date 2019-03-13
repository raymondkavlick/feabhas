#pragma once

class Step
{
    public:
        Step();
        explicit Step(int);
        ~Step(void);
        Step(const Step&) = delete;
        void set_number(int);
        void run() const;
    private:
        int state;
        int get_step();
};