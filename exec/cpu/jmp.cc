//#define XERR
#include "cpu.ih"

void CPU::jmp()
{
    auto step = d_hdr.get<int16_t>();

    xerr("jmp step " << step);    
    d_hdr.seekg(step, ios::cur);
}
