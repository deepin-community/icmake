//#define XERR
#include "semval.ih"

SemVal SemVal::incDec(Opcode::Byte opcode, ExprType prepost)
{
    if (isLvalue(opcode) and accept(opcode))
    {
        *this << opcode << as<short>(d_value);      // write ++ or -- opcode
        d_type = e_int | prepost;
    }

    return move(*this);
}
