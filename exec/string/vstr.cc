//#define XERR
#include "string.ih"

string const &String::vStr() const
{
    return d_str;
}
