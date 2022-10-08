//#define XERR
#include "unassembler.ih"

void UnAssembler::statistics() const
{
    cout << 
        "Binary file statistics:\n"
        "\tstrings      at offset\t0x" << setw(4) << 
                                           d_hdr.stringsOffset() << "\n"
        "\tvariables    at offset\t0x" << setw(4) <<
                                           d_hdr.varsOffset() << "\n"
        "\tfilename     at offset\t0x" << setw(4) <<
                                            d_hdr.filenameOffset() << "\n"
        "\tcode         at offset\t0x" << setw(4) <<
                                            d_hdr.codeOffset() << "\n"
        "\tfirst opcode at offset\t0x" << setw(4) <<
                                            d_hdr.startOffset() << "\n"
        "\n";
}
