//#define XERR
#include "tools.ih"

    // return true if the entry is younger than the referenceTime
    // non-existing entries return the begin of the epoch as last modification
    // time, so:
    //        if both don’t exist 0 is returned;
    //        if the reference doesn’t exist, 1 is returned;
    //        if the entry doesn’t exist 0 is returned;
    //        if they are equally old 0 is returned.

// static
bool Tools::younger(string const &entry, Stat const &rhs)
{
    auto modifications = times(entry, rhs);

    xerr("lhs (" << \
            modifications.first % 1'000'000 << \
            ") >  rhs (" << \
            modifications.second % 1'000'000 << \
            ") ? " << \
            (modifications.first > modifications.second) );

    return modifications.first > modifications.second;
}

