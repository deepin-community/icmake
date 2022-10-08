//#define XERR
#include "options.ih"

void Options::setVerbosity() const
{
    g_log.setLevel(V0 - min(d_arg.option('V'), as<size_t>(V0)));
            // no -V: resistance level == V0, so no levels (V1 .. V3) insert
            //        their messages
            // one -V: resistance level == V1, so only V1 level messages are
            //        shown
            // two -Vs: resistance level == V2, so V1 and V2 level messages 
            //        are shown (etc, up to four -Vs
}
