//#define XERR
#include "cpu.ih"

void CPU::atoi()
{
    d_stack.top() = stoi(d_stack.top().str());  
}
