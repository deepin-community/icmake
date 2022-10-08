//#define XERR
#include "generator.ih"

void Generator::strings()
{
    d_header.strings = d_bim.tellp();

    for (auto const &info: StringStore::instance().stringVect())
        d_bim << info.str << '\0';
}
