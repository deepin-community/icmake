//#define XERR
#include "int.ih"

VarBase &Int::vAddIs(VarBase const &rhs)
{
    d_value += rhs.value();
    return *this;
}
