//#define XERR
#include "args.ih"

bool Args::equalTypes(std::vector<ExprType> const &paramTypes) const
{
    unsigned nArgs = size();

    if (paramTypes.size() != nArgs)
        return false;

    for (size_t idx = 0; idx != nArgs; ++idx)
    {
        if (not equalMask((*this)[idx].type(), paramTypes[idx]))
            return false;
    }

    return true;
}
