#define XERR
#include "args.ih"

    // inspect arguments from the last back to the first
bool Args::trailingTypes(Builtin::ArgsIter funBegin, Builtin::ArgsIter funEnd,
                         unsigned argBegin, unsigned argEnd) const
{
    if (funEnd - funBegin > argEnd - argBegin)  // too few trailing args
        return false;
                                                // check trailing args fm the
                                                // last to the first
    for (--argEnd ; funEnd-- != funBegin; --argEnd)
    {
        if (not equalTypes(funEnd, argEnd))
            return false;
    }

    return true;
}
