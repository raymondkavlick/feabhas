#pragma once
#include "USART.h"

namespace STM32F407
{
    class SerialPort : public USART
    {
        public:
            void display(int num)
            {
                USART::send(num + '0');

            }
        private:
            void run()
            {
                while(1)
                {
                    display(1);
                }
            };
    };

}
