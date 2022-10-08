#define XERR
#include "unassembler.ih"

void UnAssembler::call_rss() const
{
    auto offset = d_hdr.offset();
    uint16_t funNr = d_hdr.get<uint8_t>();       

    display2(funNr);

    if (funNr >= BuiltinFunctions::nFunctions())
        throw Exception{} << "at offset " << offset << 
                ": request to call function " << 
                funNr << " (not builtin)";

    cout << s_1 << "callrss " << setw(2) << funNr << 
            " (" << BuiltinFunctions::name(funNr) << ')';
}
