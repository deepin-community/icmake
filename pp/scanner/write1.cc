//#define XERR
#include "scanner.ih"

void Scanner::write(int ch)
{
    out().put(ch);
}
