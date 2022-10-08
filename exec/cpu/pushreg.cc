//#define XERR
#include "cpu.ih"

// This function is called when the return register must be pushed. The
// return register is used to return information from built-in functions.

void CPU::pushReg()
{
    d_stack.push(d_reg);
}
