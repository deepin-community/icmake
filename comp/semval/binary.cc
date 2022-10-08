//#define XERR
#include "semval.ih"

    // the lhs value is pushed first, the rhs value pushed 2nd

SemVal SemVal::binary(Opcode::Byte opcode, SemVal &&rhs)
{
    xerr("lhs type: " << d_type << ", rhs type: " << rhs.d_type);

    if (accept(rhs, opcode))
    {
        if 
        (
            (d_type & rhs.type() & e_const)     // lhs, rhs both constants
            and                                 // but older,younger are 
            opcode != Opcode::older             // always run-time checked
            and 
            opcode != Opcode::younger
        )
            constBinary(opcode, rhs);
        else
        {        
            rhs.push();
        
            push();
            *this << rhs << opcode;
                                                // comparison operations 
                                                // return int values
            if (Opcode::eq <= opcode and opcode <= Opcode::greq)
                d_type = e_int;

            stackType();
        }
    }

    return move(*this);
}

