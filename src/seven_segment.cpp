#include "seven_segment.h"

#include "Scheduler.h"
#include "Thread.h"
#include <iostream>
#include "Duration.h"

using namespace FeabhOS::Time;

Seven_segment::Seven_segment()
{
    blank();

}
Seven_segment::~Seven_segment()
{
    blank();

}

void Seven_segment::blank()
{
    led3.set();
    led4.set();
    led5.set();
    led6.set();

}
void Seven_segment::display(unsigned int digit)
{
    if(digit & 1)
        led6.set();
    else
        led6.clear();

    if(digit & 2)
        led5.set();
    else
        led5.clear();


    if(digit & 4)
        led4.set();
    else
        led4.clear();


    if(digit & 8)
        led3.set();
    else
        led3.clear();
}

void Seven_segment::run()
{
    while(1)
    {
        FeabhOS::Thread::sleep(1000_ms);
        std::cout << "Seven Seg!\r\n";
    }
}

