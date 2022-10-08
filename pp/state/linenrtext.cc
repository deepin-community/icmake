//#define XERR
#include "state.ih"

void State::lineNrText()
{
    if (d_scanner.active())
        writeLineNrText();
}
