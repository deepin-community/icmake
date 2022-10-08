//#define XERR
#include "semval.ih"

    // both types must be e_str | e_const
void SemVal::catString(SemVal const &rhs)
{
    StringStore &stringStore = StringStore::instance();

    d_value = 
        stringStore.offset(
                stringStore.str(d_value) + stringStore.str(rhs.d_value)
        );
}
