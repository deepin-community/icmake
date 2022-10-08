#define XERR
#include "cpu.ih"

void CPU::div()
{
    int rhs = d_stack.top().value();

    if (rhs == 0)
        throw Exception{} << "division by 0 at " << (d_hdr.offset() - 1);

    d_stack.pop();

    d_stack.top().valueRef() /= rhs;
}
