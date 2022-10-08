//#define XERR
#include "builtin.ih"

void Builtin::strUppercase()
{
    d_reg = String::uc(d_stack[2].str());
}
