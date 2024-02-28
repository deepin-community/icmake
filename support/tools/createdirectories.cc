//#define XERR
#include "tools.ih"

bool Tools::createDirectories(fs::path const &dir)
{
    return fs::create_directories(dir, s_ec) or s_ec.value() == 0;
}
