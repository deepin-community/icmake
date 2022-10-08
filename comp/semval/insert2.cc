//#define XERR
#include "semval.ih"
 
SemVal &SemVal::insert2(short value)
{
//    if (not d_ignoreNext)
//    {

    d_code += as<uint8_t>(value);                       // LSB goes first
    d_code += as<uint8_t>(as<uint16_t>(value) / 0x100); // then the MSB

//    }

    return *this;
}
