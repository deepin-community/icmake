//#define XERR
#include "semval.ih"

SemVal::SemVal(ExprType type, int value)
:
    d_type(type),
    d_value(value)
{
    xerr("type: " << d_type << ", value: " << d_value);
}
