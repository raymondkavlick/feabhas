// -----------------------------------------------------------------------------
// Timer.cpp
//
// DISCLAIMER:
// Feabhas is furnishing this item "as is". Feabhas does not provide any
// warranty of the item whatsoever, whether express, implied, or statutory,
// including, but not limited to, any warranty of merchantability or fitness
// for a particular purpose or any warranty that the contents of the item will
// be error-free.
// In no respect shall Feabhas incur any liability for any damages, including,
// but limited to, direct, indirect, special, or consequential damages arising
// out of, resulting from, or any way connected to the use of the item, whether
// or not based upon warranty, contract, tort, or otherwise; whether or not
// injury was sustained by persons or property or otherwise; and whether or not
// loss was sustained from, or arose out of, the results of, the item, or any
// services that may be provided by Feabhas.
// -----------------------------------------------------------------------------

#include "Timer.h"
#include "cortexm/ExceptionHandlers.h"
#include "cmsis_device.h"


namespace STM32F407 {

    volatile Timer::ticks Timer::delay_count;


    Timer::Timer()
    {
        start();
    }


    void Timer::start()
    {
        // Use SysTick as reference
        // for the delay loops.
        //
        SysTick_Config(SystemCoreClock / freq_Hz);
    }


    void Timer::stop()
    {
        // To Do...
    }


    void Timer::sleep(ticks ms_to_sleep)
    {
        delay_count = ms_to_sleep;

        // Busy wait until the SysTick decrements
        // the counter to zero.
        //
        while (delay_count != 0) { /* spin... */ }
    }

    void Timer::ISR()
    {
        // Decrement to zero the counter used
        // by the delay routine.
        //
        if (delay_count != 0) {
            --delay_count;
        }
    }

} // namespace STM32F407


// ----------------------------------------------------------
// If the RTOS is enabled SysTick is used by the OS. It
// therefore cannot be used for user timing functions.
// Any calls to sleep() must be replaced with calls to 
// FeabhOS::Thread::sleep.
//
#ifdef RTOS

extern "C" void xPortSysTickHandler(void);

#include "Thread.h"
#include "Duration.h"


void sleep(std::uint32_t ms_to_sleep)
{
    FeabhOS::Thread::sleep(FeabhOS::Time::Duration { ms_to_sleep });
}

extern "C"
void SysTick_Handler(void)
{
    xPortSysTickHandler();
}


#else

extern "C"
void SysTick_Handler(void)
{
    STM32F407::Timer::ISR();
}


void sleep(std::uint32_t ms_to_sleep)
{
    static STM32F407::Timer sys_tick { };
    sys_tick.sleep(ms_to_sleep);
}

#endif
