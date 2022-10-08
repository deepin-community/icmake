//#define XERR
#include "semval.ih"

SemVal SemVal::logicOr(SemVal &&rhs) &&
{
    if (d_type & rhs.type() & e_const)      // const operands
        set(e_int | e_const,
            d_value != 0 or 
            rhs.value() != 0 or
            (d_type & e_str) or 
            (rhs.type() & e_str) 
        );
    else
    {
        asBool();
        rmJmpZero();
    
        rhs.asBool();
    
        *this << rhs;
    }

    return move(*this);
}
