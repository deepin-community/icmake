//#define XERR
#include "generator.ih"

int Generator::noBim()
{
    d_bim.setstate(ios::failbit);
    return 1;
}
