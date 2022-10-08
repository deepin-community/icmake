//#define XERR
#include "builtin.ih"

void Builtin::strElement()
{
    unsigned idx = d_stack[2].value();     // requested element
    auto &str = d_stack[3].str();          // the string to process

    d_reg =   idx >= str.size() ? string{} : string{ str[idx] };
}
