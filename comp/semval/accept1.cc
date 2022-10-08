//#define XERR
#include "semval.ih"

bool SemVal::accept(Opcode::Byte opcode) const
{
    if (Opcode::types(opcode) & d_type)
        return true;

    Error::msg(Error::ARGUMENT_MISMATCH) << Opcode::mnemonic(opcode) << "'\n";
    return false;
}
