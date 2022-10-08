//#define XERR
#include "semval.ih"

void SemVal::set(ExprType type, int value)
{
    d_type = type;
    d_value = value;
}
