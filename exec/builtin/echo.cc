//#define XERR
#include "builtin.ih"

void Builtin::echo()
{
    d_echo = d_stack[2].value() == ON;
}
