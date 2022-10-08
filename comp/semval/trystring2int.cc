#define XERR
#include "semval.ih"

bool SemVal::tryString2Int(SemVal &rhs)
{
    if (
        d_type & e_int                  // lhs must be int
        and
        rhs.type() == (e_str | e_const) // rhs must be a const. str
    )
    {
                                        // get the string
        string const &str = StringStore::instance().str(rhs.value());
        if (str.length() == 1)          // it's a 1-char string
        {
            rhs.set(e_int | e_const, str[0]);   // return the char's value
            return true;                        // as int
        }
    }

    return false;
}
