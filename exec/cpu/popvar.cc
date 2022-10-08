//#define XERR
#include "cpu.ih"

// This function is executed when an op_pop_var opcode is read
// Follwing the opcode a variable index (either global or on the stack)
// is expected. 

void CPU::popVar()
{
    variable() = d_stack.topMove();
}
