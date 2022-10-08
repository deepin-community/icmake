//#define XERR
#include "state.ih"

void State::filename()
{
    if (d_scanner.active())
        d_scanner.writeFilename();
}
