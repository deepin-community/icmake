//#define XERR
#include "cpu.ih"

void CPU::pushImm()
{
    d_stack.push( new Int{ d_hdr.get<int16_t>() } );
}
