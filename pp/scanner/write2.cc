//#define XERR
#include "scanner.ih"

void Scanner::write(char const *txt)
{
    out() << txt;
}
