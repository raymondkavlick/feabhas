#include "seven_segment.h"


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

