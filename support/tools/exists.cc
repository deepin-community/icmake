//#define XERR
#include "tools.ih"

// static
bool Tools::exists(string const &path)
{
    error_code ec;

    return filesystem::exists(path, ec);
}
