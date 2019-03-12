// -----------------------------------------------------------------------------
// USART.cpp
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

#include "USART.h"
#include <cstdint>
#include "Peripherals.h"
#include "memory_map.h"

namespace STM32F407 {

    // UART register definitions
    //
    struct USART_registers {
        std::uint32_t status;         // Status register
        std::uint32_t data;           // Data register
        std::uint32_t baud_rate;      // Baud rate register
        std::uint32_t ctrl_1;         // Control register 1
        std::uint32_t ctrl_2;         // Control register 2
        std::uint32_t ctrl_3;         // Control register 3
        std::uint32_t guard_prescale; // Guard time and prescaler register
    };

    // For this project, there is only one UART
    // - USART 3
    //
    static constexpr std::uint32_t uart_addr { 0x40004800 };


    USART::USART() : usart { reinterpret_cast<USART_registers*>(uart_addr) }
    {
        // Enable the USART clock.
        //
        Peripheral::enable(Peripheral::USART_3);

        // Stop the USART before configuring
        //
        disable();

        // Reset STOP bits
        //
        usart->ctrl_2 &= ~(3 << 12);

        // Setup 8,N,1
        //
        usart->ctrl_1 |= ((1 << 2) | (1 << 3));

        // 115.2kb based on 16MHz clk and 16x oversampling
        //
        usart->baud_rate = 0x8B;

        // Configure the Tx / Rx pins for the device
        //
        remap_IO_pins();

        enable();
    }


    void USART::enable()
    {
        usart->ctrl_1 |= (1 << 13);
    }


    void USART::disable()
    {
        usart->ctrl_1 &= ~(1 << 13);
    }


    void USART::enable_rx_interrupt()
    {
        usart->ctrl_1 |= (1 << 5);
    }


    void USART::enable_tx_interrupt()
    {
        usart->ctrl_1 |= (1 << 7);
    }


    void USART::disable_rx_interrupt()
    {
        usart->ctrl_1 &= ~(1 << 5);
    }


    void USART::disable_tx_interrupt()
    {
        usart->ctrl_1 &= ~(1 << 7);
    }


    USART::~USART()
    {
        disable();
    }


    char USART::read()
    {
        return usart->data;
    }


    void USART::write(char chr)
    {
        usart->data = chr;
    }


    void USART::send(char c)
    {
        while ((usart->status & (1 << 7)) == 0) {
            ; // Wait...
        }
        write(c);
    }


    bool USART::try_get(char& chr)
    {
        if ((usart->status & (1 << 5)) != 0) {
            chr = read();
            return true;
        }
        else {
            return false;
        }
    }


    char USART::get()
    {
        bool success {};
        char chr {};

        do {
            success = try_get(chr);
        } while (!success);

        return chr;
    }


    void USART::send(const char* str)
    {
        while (*str != '\0') {
            send(*str++);
        }
    }


    // -----------------------------------------------------------------------------
    // Each UART requires two GPIO pins to be reconfigured
    // to act as the Tx and Rx pins.  These pins are on a
    // different port, and indeed different pins, for each
    // UART.
    // Tx pin is GPIO_B Pin 10
    // Rx pin is GPIO_B Pin 11

    struct GPIO_registers {
        std::uint32_t mode;
        std::uint32_t type;
        std::uint32_t speed;
        std::uint32_t pull_up_down;
        std::uint32_t input;
        std::uint32_t output;
        std::uint32_t set_reset;
        std::uint32_t lock;
        std::uint32_t alt_fn_low;
        std::uint32_t alt_fn_high;
    };


    void USART::remap_IO_pins()
    {
        constexpr uint32_t GPIO_B_addr { STM32F407::AHB1_base + (0x400 * STM32F407::Peripheral::GPIO_B) };
        auto const GPIO_B { reinterpret_cast<volatile GPIO_registers*>(GPIO_B_addr) };

        STM32F407::Peripheral::enable(STM32F407::Peripheral::GPIO_B); // Enable GPIO port

        GPIO_B->alt_fn_high |= (0x07 << (4 * (10 % 8)));   // ALT_FN7 - USART 3
        GPIO_B->alt_fn_high |= (0x07 << (4 * (11 % 8)));   //

        GPIO_B->mode |= (0x02 << (10 * 2));                 // ALT FUNCTION
        GPIO_B->mode |= (0x02 << (11 * 2));                 //

        GPIO_B->speed |= (0x03 << (10 * 2));                // HIGH SPEED
        GPIO_B->speed |= (0x03 << (11 * 2));                //

        GPIO_B->pull_up_down |= (0x01 << (10 * 2));         // PULL UP
        GPIO_B->pull_up_down |= (0x01 << (11 * 2));         //
    }

} // namespace STM32F407
