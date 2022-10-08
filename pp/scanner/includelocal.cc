//#define XERR
#include "scanner.ih"

bool Scanner::includeLocal()
{
    if (d_active)
        nextStream(nextName('"', '"'));
    
    return d_active;
}


