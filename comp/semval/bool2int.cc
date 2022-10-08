//#define XERR
#include "semval.ih"

void SemVal::bool2int()
{
    if ((d_type & e_bool) == e_null)        // not a bool
        return;

    patchTrue(END);
    *this << Opcode::push_1_jmp_end;

    patchFalse(END);
    *this << Opcode::push_0;

    d_type = e_int | e_stack;
}
