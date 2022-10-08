//#define XERR
#include "builtin.ih"

void Builtin::getCh()
{
    d_reg = string{ as<char>(OneKey{}.get()) };
}
