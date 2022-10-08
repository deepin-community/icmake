//#define XERR
#include "cpu.ih"

void CPU::bxor()
{
    int rhs = d_stack.top().value();
    d_stack.pop();

    d_stack.top().valueRef() ^= rhs;
}
