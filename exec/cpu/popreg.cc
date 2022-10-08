//#define XERR
#include "cpu.ih"

void CPU::popReg()
{
    d_reg = d_stack.topMove();
}
