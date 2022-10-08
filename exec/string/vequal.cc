//#define XERR
#include "string.ih"

bool String::vEqual(VarBase const &rhs) const
{
    return d_str == rhs.str();
}
