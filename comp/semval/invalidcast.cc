//#define XERR
#include "semval.ih"

void SemVal::invalidCast(char const *msg)
{
    Error::msg(Error::INVALID_CAST) << msg << "'\n";
    d_type = e_null;
}
