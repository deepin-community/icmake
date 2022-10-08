//#define XERR
#include "cpu.ih"

void CPU::dec()
{
    --variable().valueRef();
}
