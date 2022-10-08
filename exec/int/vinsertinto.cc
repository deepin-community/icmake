//#define XERR
#include "int.ih"

ostream &Int::vInsertInto(ostream &out) const
{
    return out << d_value;
}
