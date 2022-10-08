//#define XERR
#include "cpu.ih"

void CPU::jmpTrue() 
{
    auto step = d_hdr.get<int16_t>();

    xerr("step: " << step);
    if (isTrue())
        d_hdr.seekg(step, ios::cur);

    xerr("leaving at " << d_hdr.offset());
}
