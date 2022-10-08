//#define XERR
#include "string.ih"

VarBase *String::vcopy() const
{
    return new String{ d_str };
}
