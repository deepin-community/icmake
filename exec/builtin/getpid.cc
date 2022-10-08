//#define XERR
#include "builtin.ih"

void Builtin::getPid()
{
    d_reg = as<int>(getpid());
}
