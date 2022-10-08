//#define XERR
#include "builtin.ih"

void Builtin::getExtension()
{
    string ext{ filesystem::path{ d_stack[2].str() }.extension().string() };

    d_reg = move(ext.empty() ? ext : ext.substr(1));
}
