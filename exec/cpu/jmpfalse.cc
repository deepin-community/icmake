//#define XERR
#include "cpu.ih"

void CPU::jmpFalse()
{
    auto step = d_hdr.get<int16_t>();

    if (not isTrue())               // look at the stack top's value
        d_hdr.seekg(step, ios::cur);
}
