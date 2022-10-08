#define XERR
#include "semval.ih"

void SemVal::asBool()
{
    if (d_type & e_bool)            // already a bool expression
        return;

    push();

    addPatchTrue(Opcode::jmp_true);
    addPatchFalse(Opcode::jmp);

    d_type = e_stack | e_bool;
}
