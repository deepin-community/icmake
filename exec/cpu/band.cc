//#define XERR
#include "cpu.ih"

void CPU::band()
{
    int rhs = d_stack.top().value();
    d_stack.pop();

    d_stack.top().valueRef() &= rhs;
}
