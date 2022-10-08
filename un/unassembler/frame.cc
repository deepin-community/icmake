//#define XERR
#include "unassembler.ih"

void UnAssembler::frame()
{
    uint16_t nLocals = d_frame.read();

    display2(nLocals);           // display the # local variables

    cout << s_1 << "frame, ";
    display2(nLocals);
    cout << "local variable" << (nLocals == 1 ? ":\n" : "s:\n");

    if (nLocals == 0)
        return;

    // initial line content: |        [0014] |
    //                        123456789012345
    cout << "               "       // shift to the data column (15 spaces)
            "   " << s_0;           // then 3 for the opcode position, 
                                    // followed by the # 0-argument spaces.

    for (int idx = 0; idx != nLocals; ++idx)
        display2(d_frame.type(-idx - 1));
}
