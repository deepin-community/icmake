//#define XERR
#include "builtin.ih"

void Builtin::getDotExtension()
{
    d_reg = filesystem::path{ d_stack[2].str() }.extension().string();
}
