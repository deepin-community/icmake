//#define XERR
#include "bimheader.ih"

uint16_t BimHeader::varType(uint16_t idx)
{
    auto offs = offset();           // current offset

    varsSection();                  // go to the var-section
    d_in.seekg(idx, ios::cur);      // skip to the intended var-byte
    auto ret = get<uint8_t>();      // retrieve the type

    d_in.seekg(offs);               // restore the org. offset

    return ret;
}
