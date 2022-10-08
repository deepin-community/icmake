//#define XERR
#include "semval.ih"
 
SemVal &SemVal::insert1(uint8_t opcode)
{
//    if (not d_ignoreNext)
    d_code += opcode;

    return *this;
}
