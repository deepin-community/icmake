//#define XERR
#include "unassembler.ih"

void UnAssembler::push_1_jmp_end() const
{
    cout << s_0 << "push int 1, jmp [" << 
                                    setw(4) << d_hdr.offset() + 1 << "]";
}
