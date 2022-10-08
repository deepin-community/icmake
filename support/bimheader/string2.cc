//#define XERR
#include "bimheader.ih"

string BimHeader::string(size_t strOffset)
{
    auto offs = offset();

    stringsSection();

    d_in.seekg(strOffset, ios::cur);

    std::string ret = string(); // get the intended string

    d_in.seekg(offs);           // restore the offset

    return ret;                 // return the string
}
