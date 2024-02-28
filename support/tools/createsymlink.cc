//#define XERR
#include "tools.ih"

// static
bool Tools::createSymlink(string const &dest, string const &link)
{
    fs::create_symlink(dest, link, s_ec);
    return s_ec.value() == 0;
}
