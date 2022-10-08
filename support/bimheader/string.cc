//#define XERR
#include "bimheader.ih"

string BimHeader::string()
{
    std::string str;
    if (not getline(d_in, str, '\0'))
        throw Exception{} << "invalid string";
    return str;
}
