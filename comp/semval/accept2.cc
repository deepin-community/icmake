//#define XERR
#include "semval.ih"

    // sameType: lhs/rhs data types are identical  or  int/bool combis
    // accept(opcode): the opcode is accepted by the calling SemVal
    
bool SemVal::accept(SemVal const &rhs, Opcode::Byte opcode) const
{
    return sameType(rhs, opcode) and accept(opcode) and rhs.accept(opcode);
}
