//#define XERR
#include "state.ih"

void State::nlText()
{
    if (d_scanner.active())
        writeNLtext();
}
