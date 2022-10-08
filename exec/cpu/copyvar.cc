//#define XERR
#include "cpu.ih"

// This function is executed when an op_copy_var opcode is read
// Following the opcode a variable index (either global or on the stack)
// is expected. The value of the variable on top of the stack is assigned to 
// the variable whose index is provided as argument

void CPU::copyVar()
{
    variable() = d_stack.top();
}
