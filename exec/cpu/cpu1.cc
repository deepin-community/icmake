//#define XERR
#include "cpu.ih"

CPU::CPU(BimHeader &hdr, Stack &stack)
:
    d_hdr(hdr),
    d_stack(stack),
    d_global(hdr),
    d_builtin(d_reg, d_stack)
{}
