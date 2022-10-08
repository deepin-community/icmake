//#define XERR
#include "builtin.ih"

// the lowest index in a string
// haystack [2] where a character in needle [3] was found. 
// If not found, -1 is returned.

void Builtin::strChr()
{
    size_t idx = d_stack[2].str().find_first_of(d_stack[3].str());

    d_reg =   idx == string::npos ? -1 : idx;
}
