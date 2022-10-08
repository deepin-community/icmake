//#define XERR
#include "unassembler.ih"

void UnAssembler::disassemble()
{
    cout << "Disassembled code:\n";

    d_hdr.codeSection();

    while (not d_hdr.endCode())
    {
        uint32_t offset = d_hdr.offset();
        uint16_t opCode = d_hdr.get<uint8_t>(); // get the next opcode

        if (not Opcodes::valid(opCode))
            throw Exception{} << "At offset 0x" << setw(4) << offset << 
                        ": opcode 0x" << setw(2) << opCode << " not defined";

        cout << "\t[" << setw(4) << offset << "] " << setw(2) << 
                                                                opCode << ' ';
        disassemble(opCode);
    }

    cout.put('\n');
}
