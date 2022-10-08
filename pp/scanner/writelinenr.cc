//#define XERR
#include "scanner.ih"

void Scanner::writeLineNr()
{
    out() << lineNr();
}
