#define XERR
#include "semval.ih"

    // lhs @= rhs becomes: 
    //      push lhs, push rhs, @, copy lhs (-> pop lhs if it's the last
    //                                          step of the expression)
SemVal SemVal::compound(Opcode::Byte opcode, SemVal &&rhs)
{
    if (not assignable(opcode, rhs))
        return move(*this);

        // a (compound) assignment is always handled by code:
        // lhs code | rhs code | operation | copy_var to lhs
    push();
    rhs.push();

    *this << rhs << opcode << Opcode::copy_var << as<short>(d_value);

    d_type = (d_type & e_mask) | e_var;

    return move(*this);
}
