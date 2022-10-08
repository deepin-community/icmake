//#define XERR
#include "builtin.ih"

void Builtin::argHead()
{
    d_argHead = d_stack[2].str();
}
