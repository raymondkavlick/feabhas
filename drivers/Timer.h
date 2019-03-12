// -----------------------------------------------------------------------------
// Timer.h
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

#ifndef TIMER_H_
#define TIMER_H_

#include <cstdint>

// A utility sleep() function.  This function
// can only be used when the RTOS is disabled.
// If you have any calls to sleep() in your code
// with the RTOS enabled you will get link-time
// errors.
// You can replace the sleep() calls with calls
// to FeabhOS::Thread::sleep() instead.
//
void sleep(std::uint32_t ms_to_sleep);

extern "C"
void SysTick_Handler(void);


namespace STM32F407 {

    class Timer {
    protected:
        // The Timer has a protected interface
        // to stop users creating their own
        // Timer objects.
        // Only the sleep() function can
        // create a Timer object.
        // The SysTick_Handler() is a CMSIS-
        // provided ISR function that calls
        // back on the private Timer::ISR()
        // function.
        //
        friend void ::sleep(std::uint32_t);
        friend void ::SysTick_Handler(void);

        using ticks = std::uint32_t;

        Timer();

        void start();
        void stop();
        static void sleep(ticks t);

    private:
        static void ISR();
        static constexpr ticks freq_Hz { 1000 };
        static volatile ticks  delay_count;
    };

} // namespace STM32F407

#endif // TIMER_H_
