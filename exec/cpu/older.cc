//#define XERR
#include "cpu.ih"

void CPU::older()
{
    Stat rhs{ d_stack.top().str() };
    d_stack.pop();


    xerr(d_stack.top().str() << " older " << rhs.name());

    d_stack.top() = as<int>(Tools::older(d_stack.top().str(), rhs));
}
