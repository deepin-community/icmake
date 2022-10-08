//#define XERR
#include "string.ih"

ostream &String::vInsertInto(ostream &out) const
{
    return out << d_str;
}
