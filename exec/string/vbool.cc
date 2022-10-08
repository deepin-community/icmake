//#define XERR
#include "string.ih"

bool String::vBool() const
{
    return not d_str.empty();
}
