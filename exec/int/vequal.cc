//#define XERR
#include "int.ih"

bool Int::vEqual(VarBase const &rhs) const
{
    return d_value == rhs.value();
}
