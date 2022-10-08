#define XERR
#include "symtab.ih"

SemVal Symtab::makeFrame() const
{
    SemVal frame;

    if (not d_locals.empty())
    {
        frame << Opcode::frame << as<uint8_t>(d_locals.size());
        
        for (ExprType type: d_locals)           // process the local variables
            frame << as<uint8_t>(type);
    }

    return frame;
}
