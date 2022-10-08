//#define XERR
#include "cpu.ih"

void CPU::shr()
{
    int rhs = d_stack.top().value();
    d_stack.pop();

    d_stack.top().valueRef() >>= rhs;
}
