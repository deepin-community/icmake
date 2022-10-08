//#define XERR
#include "cpu.ih"

// asp is followed by a 1 byte argument specifying the #elements to pop.

void CPU::asp()
{
    d_stack.asp(d_hdr.get<uint8_t>());
}
