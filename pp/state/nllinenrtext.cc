//#define XERR
#include "state.ih"

void State::nlLineNrText()
{
    if (not d_scanner.active())
        return;

    d_scanner.write('\n');
    writeLineNrText();
}
