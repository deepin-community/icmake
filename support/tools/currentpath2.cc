//#define XERR
#include "tools.ih"

void Tools::currentPath(fs::path const &next)
{
    fs::current_path(next, s_ec);
}
