//#define XERR
#include "unassembler.ih"

void UnAssembler::disassemble(uint16_t opCode)
{
    // opcode     mnemonic
    // 23         ret
    //    12345678
    // A blank is appended to the opcode. Therafter there are 8 char columns
    // available until the mnemonic is displayed. 

    (this->*s_disassemble[opCode].plain)();

    cout.put('\n');
}
