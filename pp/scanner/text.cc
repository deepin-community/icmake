//#define XERR
#include "scanner.ih"

void Scanner::text()
{
    out() << matched();
}
