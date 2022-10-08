//#define XERR
#include "semval.ih"

SemVal SemVal::bitNot()
{
    if (accept(Opcode::bnot))
    {
        if (d_type & e_const)                  // a mere value is available
            d_value = ~d_value;
        else
        {
            push();
            *this << Opcode::bnot;
        }
    }
    return move(*this);
}
