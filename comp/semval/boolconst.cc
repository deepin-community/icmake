#define XERR
#include "semval.ih"

bool SemVal::boolConst() const
{
    switch (static_cast<int>(d_type))
    {
        case e_int | e_const:
        return d_value != 0;

        case e_str | e_const:
        return StringStore::instance().str(d_value).length();

        default:
        return false;
    }
}
