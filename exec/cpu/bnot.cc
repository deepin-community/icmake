//#define XERR
#include "cpu.ih"

void CPU::bnot()
{
    d_stack.top().valueRef() = ~d_stack.top().value();
}
