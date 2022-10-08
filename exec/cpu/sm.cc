//#define XERR
#include "cpu.ih"

void CPU::sm()
{
    Variable rhs = d_stack.topMove();

    d_stack.top() =  d_stack.top() < rhs;
}
