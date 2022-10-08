//#define XERR
#include "cpu.ih"

void CPU::neq()
{
    Variable rhs = d_stack.topMove();

    d_stack.top() =  d_stack.top() != rhs;
}

