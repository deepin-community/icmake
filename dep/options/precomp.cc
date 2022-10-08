//#define XERR
#include "options.ih"

void Options::precomp()
{
    if (d_gch != UNSPECIFIED)
        return;

    d_gch = GCH;
    g_log << level(V1) << "inspecting precompiled headers (.gch files)\n";
}
