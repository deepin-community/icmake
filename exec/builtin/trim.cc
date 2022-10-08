//#define XERR
#include "builtin.ih"

void Builtin::trim()
{
    d_reg = String::trim(d_stack[2].str());
}
