//#define XERR
#include "generator.ih"

void Generator::filenames()
{
    d_header.filenames = d_bim.tellp();
    d_bim << d_scanner.filenames();
}
