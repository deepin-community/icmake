//#define XERR
#include "semval.ih"

bool SemVal::assignable(Opcode::Byte opcode, SemVal &rhs) const
{
    if ( (d_type & e_var) and sameType(rhs.type(), opcode) )
        return true;

    Error::msg(Error::OPERAND_TYPES) << "='\n";
    return false;
}
