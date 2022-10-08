//#define XERR
#include "semval.ih"

SemVal SemVal::boolNot()
{
    if (d_type & e_const)              // immediate value 
        set(e_int | e_const, not( (d_type & e_str) or d_value != 0 ) );
                                // strings: always 'true', ints: != 0: true
    else
    {
        asBool();
        swapTrueFalse();
    }

    return move(*this);
}
