//#define XERR
#include "scanner.ih"

void Scanner::writeFilename()
{
    out() << "#>" << filename() << '\n';
}
