//#define XERR
#include "builtin.ih"

void Builtin::cmdTail()
{
    d_cmdTail = d_stack[2].str();
}
