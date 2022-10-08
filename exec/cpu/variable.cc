//#define XERR
#include "cpu.ih"

Variable &CPU::variable()
{
    auto index = d_hdr.get<int16_t>();

    // see the unassembler/handleVar function about the 0xc000 shift.

//    if (index >= 0)
//        xerr("global: " << index << ", value: " << d_global[index]);
    
    return index >= 0 ? d_global[index] : d_stack[index -= 0xc000];
}
