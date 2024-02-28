//#define XERR
#include "bimheader.ih"

void BimHeader::checkOffsets() const
{
    for (
        auto [size, begin, end] = tuple{ 
                                      fs::file_size(d_bimName), 
                                      &d_hdr.strings, 
                                      &d_hdr.firstOpcode + 1 
                                  };
            begin != end;
                ++begin
    )
    {
        if (*begin >= size)
            throw Exception{} << "invalid offsets in " << d_bimName;
    }
}
