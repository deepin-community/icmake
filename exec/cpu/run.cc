//#define XERR
#include "cpu.ih"

size_t counter = 0;

int CPU::run()
{
    d_hdr.start();                  // at the first instruction to execute

    Opcodes::Byte opcode;
    do
    {
        uint32_t offset = d_hdr.offset();
        opcode = as<Opcodes::Byte>(d_hdr.get<uint8_t>());    // next opcode

        if (not Opcodes::valid(opcode))
            throw Exception{} << "At offset 0x" << setw(4) << offset << 
                        ": opcode 0x" << setw(2) << opcode << " not defined";

        xerr(ios::dec << ++counter << hex << ": at " << offset << \
            ": opcode " << opcode << " (" << Opcodes::mnemonic(opcode) << ')');

        (this->*s_execute[opcode])();
//        xerr("executed " << opcode);
    }
    while (opcode != Opcodes::Byte::exit);

    xerr("leaving");
    return d_reg.forcedInt();           // force an int-value
}









