//#define XERR
#include "unassembler.ih"

// static
void UnAssembler::display4(uint16_t value)
{
                        // low byte                    high byte
    cout << setw(2) << (value & 0xff) << ' ' << 
                                            setw(2) << (value >> 8) << ' ';
}
