//#define XERR
#include "args.ih"

bool Args::builtin(SemVal &ret, string const &name)
{
    auto function = Builtin::find(name);

    if (not typesMatch(function))
        return false;

    ret = callBuiltin(function);

    return true;
}
