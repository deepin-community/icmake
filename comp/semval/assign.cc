#define XERR
#include "semval.ih"

                                                // pop_var or copy_var
SemVal SemVal::assign(SemVal &&rhs, Opcode::Byte opcode)
{
    if (not isLvalue("="))
        return move(*this);

    if (not tryString2Int(rhs))     // if d_type & e_int: 'a' etc -> int value
        rhs.bool2int();             // maybe rhs is bool? convert to int

                                    // for '=': same types required
    if ((d_type & rhs.type() & e_mask) == e_null)
    {
        Error::msg(Error::OPERAND_TYPES) << "='\n";
        return move(*this);
    }

    rhs.push();                     // push the rhs expression on the stack
                                    // and perform the assignment
    *this << Opcode::pop_var << as<short>(d_value);

    rhs << *this;                                 // append lhs's code    

    rhs.set(d_type, d_value);

    return move(rhs);
}





