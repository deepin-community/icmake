//#define XERR
#include "int.ih"

strong_ordering Int::vOrder(VarBase const &rhs) const
{
    return d_value < rhs.value() ? strong_ordering::less    :
           d_value > rhs.value() ? strong_ordering::greater :
                                   strong_ordering::equal;
}                           
