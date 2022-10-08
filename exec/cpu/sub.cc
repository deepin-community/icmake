//#define XERR
#include "cpu.ih"

void CPU::sub()
{
    Variable rhs = d_stack.topMove();

    d_stack.top() -= rhs;
}
