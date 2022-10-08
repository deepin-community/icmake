//#define XERR
#include "cpu.ih"

void CPU::atol()
{                                               // define a list of 1 element
    d_stack.top() = new List{ vector<string>{ d_stack.top().str() } };  
}
