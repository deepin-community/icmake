#define XERR
#include "dependencies.ih"

void Dependencies::removeGch()
{
    if (d_options.go() != GO)         // no .gch checks requested
        return;
    
    size_t idx = 0;
    while ((idx = findIdx(d_indicator, idx, true)) != d_size)
    {
        Tools::mustChangeDir(d_directory[idx]);
        Tools::remove(d_localHeader[idx][0] + ".gch");
        d_options.startDir();
        ++idx;
    }
}
