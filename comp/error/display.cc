//#define XERR
#include "error.ih"

bool Error::display()
{
    ++s_nErrors;

    if (s_lastLine != g_lineNr)
    {
        s_lastLine = g_lineNr;
        s_displayCount = 0;
    }

    return ++s_displayCount <= MAX_PER_LINE;
}
