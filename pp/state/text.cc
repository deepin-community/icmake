//#define XERR
#include "state.ih"

void State::text()
{
    if (d_scanner.active())
        text2content();
}
