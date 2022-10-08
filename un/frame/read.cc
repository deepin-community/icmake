//#define XERR
#include "frame.ih"

uint8_t Frame::read()
{
    auto ret = d_hdr.get<uint8_t>();

    if (ret == 0)
        clear();
    else
    {
        resize(ret);            // resize to the required #local variables
                                // read the types:
        d_hdr.read(&front(), size());
    }

    return ret;
}
