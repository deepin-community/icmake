//#define XERR
#include "generator.ih"

Generator::~Generator()
{
    error_code ec;

    if (not d_bim)
        filesystem::remove(d_bimName, ec);
}
