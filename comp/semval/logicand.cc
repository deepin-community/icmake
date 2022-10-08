//#define XERR
#include "semval.ih"

SemVal SemVal::logicAnd(SemVal &&rhs) &&
{
xerr("lhs type: " << d_type << ", rhs type: " << rhs.d_type);

    if (d_type & rhs.type() & e_const)      // const operands
        set(e_int | e_const,
            ( d_value != 0 or (d_type & e_str) )
            and
            ( rhs.value() != 0 or (rhs.type() & e_str) ) );
    else
    {
        asBool();
        patchTrue(END);
    
        rhs.asBool();
        *this << rhs;
    }

xerr("retun type: " << d_type);

    return move(*this);
}
