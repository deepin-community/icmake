//#define XERR
#include "unassembler.ih"

UnAssembler::UnAssembler(BimHeader &hdr)
:
    d_hdr(hdr),
    d_frame(d_hdr)
{}
