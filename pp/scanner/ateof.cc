//#define XERR
#include "scanner.ih"

int Scanner::atEOF()
{
    if (not popStream())
    {
        out().put('\n');            // end the last line
        leave(0);                   // processed all nested streams
    }

    StreamData const &sd = d_streamData.top();
    Tools::changeDir(sd.path);      // return to the former dir.

    d_streamData.pop();

    return AT_EOF;
}


