//#define XERR
#include "unassembler.ih"

void UnAssembler::asp() const
{
    auto add = d_hdr.get<uint8_t>();       

    display2(add);

    cout << s_1 << "add sp, " << setw(2) << static_cast<uint16_t>(add);
}
