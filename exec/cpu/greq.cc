//#define XERR
#include "cpu.ih"

void CPU::greq()
{
    Variable rhs{ d_stack.topMove() };

    d_stack.top() =  d_stack.top() >= rhs;
}
