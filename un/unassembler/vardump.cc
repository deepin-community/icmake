//#define XERR
#include "unassembler.ih"

void UnAssembler::varDump() const
{
    if (not d_hdr.hasVariables())
        return;

    cout << "Variable section dump:\n";

    d_hdr.varsSection();

    size_t idx = 0;
    while (not d_hdr.endVars())
        cout << "\tvariable " << setw(4) << idx++ << ": " << 
                s_typeName[d_hdr.get<uint8_t>()] << '\n';

    cout.put('\n');
}
