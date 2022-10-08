//#define XERR
#include "semval.ih"

bool SemVal::sameType(SemVal const &rhs, Opcode::Byte opcode) const
{
    if ( 
        (d_type & rhs.d_type & e_mask) 
        or 
        ( (d_type & e_intMask) and (rhs.d_type & e_intMask) )
    )
        return true;            // types are identical, or an int/bool combi

    Error::msg(Error::OPERAND_TYPES) << Opcode::mnemonic(opcode) << "'\n";
    return false;
}
