#define XERR
#include "bimheader.ih"

// static
string BimHeader::bimName(char const *fname)
{
    fs::path fpath{ fname };

    if (not Tools::exists(fpath) and fpath.extension().empty())
        fpath.replace_extension(".bim");

    return fpath.string();
}
