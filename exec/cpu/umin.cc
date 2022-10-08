//#define XERR
#include "cpu.ih"

void CPU::umin()
{
    d_stack.top().valueRef() = -d_stack.top().value();
}
