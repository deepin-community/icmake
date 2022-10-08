//#define XERR
#include "cpu.ih"

void CPU::add()
{
    Variable rhs{ d_stack.topMove() };

    d_stack.top() += rhs;
}
