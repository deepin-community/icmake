//#define XERR
#include "options.ih"

void Options::setUseAll()
{
    string const &value = s_icmconf[2];

    if (value.empty() || d_useAll[0] != 0)  // [0] != 0: already specified
        return;

    d_useAll = value;
    g_log << level(V1) << "inspecting USE_ALL files: `" << d_useAll << "'\n";
}
