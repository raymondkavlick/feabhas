#pragma once
#include "Peripherals.h"
#include "SerialPort.h"

extern "C" void USART3IRQ_Handler();


namespace WMS
{
    class OutputDevice : public STM32F407::SerialPort
    {
        public:
            virtual void display(int val)
            {
                STM32F407::SerialPort::display(val);
            };
            virtual ~OutputDevice() = default;
    };
}