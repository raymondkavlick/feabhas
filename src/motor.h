#include "pin.h"

namespace WMS
{

    class Motor
    {
    public:
        Motor();
        ~Motor();
        void on();
        void off();
        void change_direction();

    private:
        STM32F407::Pin motor_control_pin{STM32F407::Peripheral::GPIO_D,12};
        STM32F407::Pin motor_dir_pin{STM32F407::Peripheral::GPIO_D,13};
    };

}