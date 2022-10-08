//#define XERR
#include "cpu.ih"

void CPU::pushStrConst()
{
    d_stack.push( new String{ d_hdr.string(d_hdr.get<uint16_t>()) } );
}
