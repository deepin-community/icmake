//#define XERR
#include "builtin.ih"

void Builtin::strFind()
{
    size_t idx = d_stack[2].str().find(d_stack[3].str());

    d_reg =   idx == string::npos ? -1 : idx;
}
