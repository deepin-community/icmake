//#define XERR
#include "semval.ih"

void SemVal::continueStmnt()
{
    addPatch(d_patchContinue, Opcode::jmp);
    d_state = DEAD;
}
