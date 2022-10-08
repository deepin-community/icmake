//#define XERR
#include "unassembler.ih"

void UnAssembler::push_imm() const
{
    auto value = d_hdr.get<uint16_t>();       

    display4(value);                   // display as uint16_t

    cout << s_2 << "push int " << setw(4) << value;
}
