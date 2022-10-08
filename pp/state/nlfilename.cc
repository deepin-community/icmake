//#define XERR
#include "state.ih"

void State::nlFilename()
{
    if (not d_scanner.active())
        return;

    d_scanner.write('\n');
    d_scanner.writeFilename();

    d_state = START;
}
