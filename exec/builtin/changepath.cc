//#define XERR
#include "builtin.ih"

// stack[2] contains the filename, [3] specifies the new path component

void Builtin::changePath()
{
    filesystem::path file{ filesystem::path{ d_stack[2].str() }.filename() };

    d_reg = (filesystem::path{ d_stack[3].str() } /= file).string();
}
