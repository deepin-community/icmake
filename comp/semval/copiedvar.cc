//#define XERR
#include "semval.ih"

bool SemVal::copiedVar()
{
    if (d_lastOpcode != Opcode::pop_var)
        return false;

    d_lastOpcode = Opcode::copy_var;
    d_code[d_code.size() - sizeof(short) - 1] = d_lastOpcode;
    
    return true;
}
