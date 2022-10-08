//#define XERR
#include "unassembler.ih"

void UnAssembler::jmp() const
{
    auto jmpSize = d_hdr.get<uint16_t>();       

    display4(jmpSize);                   // display as uint16_t

    cout << s_2 << "jmp [" << setw(4) << 
                            as<int16_t>(d_hdr.offset() + jmpSize) << "]";
}
