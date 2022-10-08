//#define XERR
#include "bimheader.ih"

bool BimHeader::atOffset(uint32_t offset)
{
    return static_cast<uint32_t>(d_in.tellg()) == offset;
}
