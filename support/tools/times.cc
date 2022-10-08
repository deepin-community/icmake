//#define XERR
#include "tools.ih"

// static
pair<time_t, time_t> Tools::times(string const &entry, Stat const &rhs)
{
    Stat lhs = Stat{ entry };
    
    return {
               lhs ? lhs.lastModification().utcSeconds() : 0,
               rhs ? rhs.lastModification().utcSeconds() : 0
           };
}
