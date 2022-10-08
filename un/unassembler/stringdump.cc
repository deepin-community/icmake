//#define XERR
#include "unassembler.ih"

void UnAssembler::stringDump() const
{
    if (not d_hdr.hasStrings())
        return;

    cout << "String constants dump:\n";

    d_hdr.stringsSection();
    uint32_t begin = d_hdr.offset();

    while (not d_hdr.endStrings())
    {
        uint32_t current = d_hdr.offset();

        cout << "\t[" << setw(4) << current << " (" << setw(4) <<
                 (current - begin) << ")] ";
        display(d_hdr.string());
        cout.put('\n');
    }

    cout.put('\n');
}



