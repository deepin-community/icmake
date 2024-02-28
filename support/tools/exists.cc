//#define XERR
#include "tools.ih"

// static
bool Tools::exists(string const &path)
{
    return fs::exists(path, s_ec);
}
