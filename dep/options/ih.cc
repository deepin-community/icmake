//#define XERR
#include "options.ih"

void Options::ih()
{
    string const &value = s_icmconf[2];

    if (value.empty())
        return;

    d_ih = value;
    g_log << level(V2) << "used header extension: `" << d_ih << "'\n";
}
