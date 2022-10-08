//#define XERR
#include "dependencies.ih"

void Dependencies::useAllIndicator()
{
    d_indicator.clear();

    for (size_t idx = 0; idx != d_size; ++idx)
    {
        Tools::changeDir(d_directory[idx]);
        d_indicator.push_back(Tools::exists(d_useAll));
        d_options.startDir();
    }
}
