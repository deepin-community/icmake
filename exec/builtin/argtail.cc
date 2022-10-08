//#define XERR
#include "builtin.ih"

void Builtin::argTail()
{
    d_argTail = d_stack[2].str();
}
