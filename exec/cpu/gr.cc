//#define XERR
#include "cpu.ih"

void CPU::gr()
{
    Variable rhs{ d_stack.topMove() };

    xerr(d_stack.top() << " > " << rhs);

    d_stack.top() =  d_stack.top() > rhs;

    xerr(" = " << d_stack.top());
}
