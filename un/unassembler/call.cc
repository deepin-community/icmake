//#define XERR
#include "unassembler.ih"

void UnAssembler::call() const
{
    auto address = d_hdr.get<uint16_t>();       

    display4(address);

    cout << s_2 << "call [" << setw(4) << address << ']';
}
