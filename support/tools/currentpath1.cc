//#define XERR
#include "tools.ih"

Tools::Path Tools::currentPath()
{
    return fs::current_path(s_ec);
}
