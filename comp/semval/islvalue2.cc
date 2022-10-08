//#define XERR
#include "semval.ih"

bool SemVal::isLvalue(char const *mnemonic) const
{
    if (d_type & e_var)
        return true;

    Error::msg(Error::LVALUE_NEEDED) << mnemonic << "'\n";
    return false;
}
