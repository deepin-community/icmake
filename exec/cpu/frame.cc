//#define XERR
#include "cpu.ih"

void CPU::frame()
{
    xerr("");
    for (                                   // get the # local variables
        uint16_t idx = 0, end = d_hdr.get<uint8_t>();
            idx != end;
                ++idx
    )
            d_stack.push( variableFactory() );  // push them on the stack
}   
