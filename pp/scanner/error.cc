#include "scanner.ih"

ostream &Scanner::error()
{
    ++d_nErrors;
    out().setstate(ios::failbit);
    return cerr << '\n' << filename() << " [" << lineNr() << "] error: ";
}
