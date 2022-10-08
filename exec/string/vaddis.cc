//#define XERR
#include "string.ih"

VarBase &String::vAddIs(VarBase const &rhs)
{
    d_str += rhs.str();
    return *this;
}
