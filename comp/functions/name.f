//#define XERR
#include "functions.ih"

inline string const &Functions::name() const
{
    return isMain() ? s_main : d_overload->first;
}
