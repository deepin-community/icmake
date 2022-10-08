//#define XERR
#include "unassembler.ih"

// static
UnAssembler::VarType UnAssembler::varType(uint16_t *index)
{
    if (*index < 0x8000)
        return GLOBAL;                  // global var, index is its index

    VarType ret = *index < 0xc000 ? LOCAL : ARG;

    *index -= 0xc000;                   // *index is BP offset

    return  ret;
}                   
