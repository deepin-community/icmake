//#define XERR
#include "state.ih"

void State::spaceText()
{
    if (not d_scanner.active())
        return;

    d_scanner.write(' ');
    text();
}
