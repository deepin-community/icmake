//#define XERR
#include "tools.ih"

    // return true if the entry is older than the referenceTime
    // non-existing entries return the begin of the epoch as last modification
    // time, so:
    //        if both don’t exist 0 is returned;
    //        if the reference doesn’t exist, 1 is returned;
    //        if entry doesn’t exist 0 is returned;
    //        if they are equally old 0 is returned.

// static
bool Tools::older(string const &entry, Stat const &rhs)
{
    auto modifications = times(entry, rhs);

    xerr(modifications.first << " < " << modifications.second);

    return modifications.first < modifications.second;
}

