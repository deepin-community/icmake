//#define XERR
#include "semval.ih"

void SemVal::breakStmnt()
{
    addPatch(d_patchBreak, Opcode::jmp);
    d_state = DEAD;
}
