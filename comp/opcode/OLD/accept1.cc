//#define XERR
#include "opcode.ih"

// static
bool Opcode::accept(Byte opcode, ExprType type)
{
    if (s_info[opCode].types & type)
        return true;

    Error::semantic(Error:ARGUMENT_MISMATCH) << mnemonic(opcode) << "'\n";
    return false;
}
