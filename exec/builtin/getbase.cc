//#define XERR
#include "builtin.ih"

void Builtin::getBase()
{
    d_reg = filesystem::path{ d_stack[2].str() }.stem().string();
}
