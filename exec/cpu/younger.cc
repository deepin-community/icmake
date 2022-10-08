//#define XERR
#include "cpu.ih"

void CPU::younger()
{
    Stat rhs{ d_stack.top().str() };
    d_stack.pop();

    xerr(d_stack.top().str() << " younger " << rhs.name());

    d_stack.top() = as<int>(Tools::younger(d_stack.top().str(), rhs));
}
