//#define XERR
#include "builtin.ih"

void Builtin::exists()
{
    d_reg = Tools::exists(d_stack[2].str());
}
