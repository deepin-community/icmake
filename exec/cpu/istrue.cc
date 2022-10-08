//#define XERR
#include "cpu.ih"

bool CPU::isTrue()
{
    xerr("");
    bool ret = d_stack.top().isTrue();
    xerr("ret = " << ret);
    d_stack.pop();
    return ret;
}
