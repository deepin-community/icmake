//#define XERR
#include "builtin.ih"

void Builtin::listLen()
{
    d_reg = d_stack[2].list().size();
}
