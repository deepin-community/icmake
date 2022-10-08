//#define XERR
#include "builtin.ih"

void Builtin::getPath()
{
    d_reg = filesystem::path{ d_stack[2].str() }.remove_filename().string();
}
