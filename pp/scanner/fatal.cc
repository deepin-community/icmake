//#define XERR

#include "scanner.ih"

Exception Scanner::fatal() const
{
    return Exception{} << '\n' << filename() << " [" << lineNr() << 
                                                                "] fatal: ";
}
