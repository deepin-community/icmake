#define XERR
#include "args.ih"

bool Args::initialTypes(Builtin::Function function, 
                        Builtin::ArgsIter &funBegin, Builtin::ArgsIter funEnd,
                        unsigned &argBegin, unsigned argEnd)
{
                                                // inspect all types or until
                                                // e_null
    for (; funBegin != funEnd; ++funBegin, ++argBegin)    
    {
        if (*funBegin == e_null)                // e_null: variable #args ok
        {
            ++funBegin;                         // continue beyond
            break;
        }

        if (
            argBegin == argEnd                  // not enough arguments
            or                                  // or types differ: no builtin
            not equalTypes(funBegin, argBegin)
        )
            return false;
    }

    return true;
}
