//#define XERR
#include "builtin.ih"

void Builtin::strLowercase()
{
    d_reg = String::lc(d_stack[2].str());
}
