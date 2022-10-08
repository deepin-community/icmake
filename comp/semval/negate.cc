//#define XERR
#include "semval.ih"

SemVal SemVal::negate()
{
    if (accept(Opcode::umin))
    {
        if (d_type & e_const)                  // a mere value is available
            d_value = -d_value;
        else
        {
            push();
            *this << Opcode::umin;
        }
    }
    return move(*this);
}






