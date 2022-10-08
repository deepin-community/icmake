//#define XERR
#include "cpu.ih"

void CPU::ret()
{
    d_stack.popBP();

    xerr("ret " << d_stack.top().value());


                                // continue at the function's return address
    d_hdr.seekg(d_stack.top().value());

    d_stack.pop();              // remove the return value fm the stack
}
