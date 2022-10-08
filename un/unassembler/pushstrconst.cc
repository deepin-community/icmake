//#define XERR
#include "unassembler.ih"

void UnAssembler::push_strconst() const
{
    auto offset = d_hdr.get<uint16_t>();

    display4(offset);                   // display the index

    cout << s_2 << "push string ";

    display(d_hdr.string(offset));      // get the string given its index
}
