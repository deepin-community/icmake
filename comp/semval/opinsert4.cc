#define XERR
#include "semval.ih"

SemVal &operator<<(SemVal &semVal, Opcode::Byte opcode)
{
    return semVal.insert1(as<uint8_t>(SemVal::s_lastOpcode = 
                                        semVal.d_lastOpcode = opcode) );
}
