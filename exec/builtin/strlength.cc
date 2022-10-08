//#define XERR
#include "builtin.ih"

void Builtin::strLength()
{
    d_reg = d_stack[2].str().length();
}
