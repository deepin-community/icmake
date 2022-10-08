//#define XERR
#include "cpu.ih"

void CPU::inc()
{
    ++variable().valueRef();
}
