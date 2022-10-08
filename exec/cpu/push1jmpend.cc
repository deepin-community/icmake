//#define XERR
#include "cpu.ih"

// This function serves the evaluation of logical expressions. It is
// executed when an op_push_1_jmp_end opcode is found in the
// bim file. A variable of type Int{1} is pushed on the stack.
// After this, the next opcode (which is by definition 'push 0') is skipped.

void CPU::push1jmpEnd()
{
    d_stack.push( new Int{ 1 } );
    d_hdr.seekg(1, ios::cur);   // skip the next opcode (= 'push 0')
}
