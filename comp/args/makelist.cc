#define XERR
#include "args.ih"

bool Args::makelist(Builtin::ArgsIter funBegin, Builtin::ArgsIter funEnd,
                    unsigned argBegin, unsigned argEnd)
{
    if (argEnd - argBegin == 0)                     // zero trailing args: OK
        return true;

    if (funEnd - funBegin != argEnd - argBegin)     // # specs/args differ
        return false;

                                                    // check trailing args
    for (; funBegin != funEnd; ++funBegin, ++argBegin)
    {
        if (not equalTypes(funBegin, argBegin))
            return false;
    }

    return true;
}
