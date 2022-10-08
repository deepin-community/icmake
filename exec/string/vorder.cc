//#define XERR
#include "string.ih"

strong_ordering String::vOrder(VarBase const &rhs) const
{
    return d_str < rhs.str() ? strong_ordering::less    :
           d_str > rhs.str() ? strong_ordering::greater :
                               strong_ordering::equal;
}
