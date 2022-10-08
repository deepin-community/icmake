//#define XERR
#include "int.ih"

VarBase &Int::vSubIs(VarBase const &rhs)
{
    d_value -= rhs.value();
    return *this;
}

