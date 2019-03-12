#pragma once

namespace WMS
{
    void gpio_init();
    void motor_on();
    void motor_off();
    void motor_chg_dir();
    void seg_blank();
    void seg_set(unsigned int);
    void show_array();
}