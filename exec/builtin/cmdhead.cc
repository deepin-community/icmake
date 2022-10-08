//#define XERR
#include "builtin.ih"

void Builtin::cmdHead()
{
    d_cmdHead = d_stack[2].str();
}
