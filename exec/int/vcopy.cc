//#define XERR
#include "int.ih"

VarBase *Int::vcopy() const
{
    return new Int{ d_value };
}
