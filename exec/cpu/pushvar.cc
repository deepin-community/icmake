//#define XERR
#include "cpu.ih"

// This function is executed when an op_push_var opcode is read
// Follwing the opcode a variable index (either global or on the stack)
// is expected. This variable is pushed onto the stack.

void CPU::pushVar()
{
    d_stack.push(variable());
}
