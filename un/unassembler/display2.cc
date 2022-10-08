//#define XERR
#include "unassembler.ih"

// static
void UnAssembler::display2(uint16_t value)
{
    cout << setw(2) << static_cast<uint16_t>(value) << ' ';
}
