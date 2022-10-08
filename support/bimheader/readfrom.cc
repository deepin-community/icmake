#define XERR
#include "bimheader.ih"

void BimHeader::readFrom(uint32_t offset)
{
    d_in.seekg(offset);

    if (not d_in)
        throw Exception{} << "can't reach offset 0x" << offset;
}
