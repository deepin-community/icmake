//#define XERR
#include "list.ih"

bool List::vEqual(VarBase const &rhs) const
{
    return d_list == rhs.list();
}


