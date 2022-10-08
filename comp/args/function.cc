//#define XERR
#include "args.ih"

bool Args::function(SemVal &ret, Functions::Overload const *overloads)
{
    if (overloads == 0)
        return false;

    for (Functions::Info const &info: *overloads)
    {
        if (equalTypes(info.params))
            return callFunction(ret, info);
    }

    return false;
}
