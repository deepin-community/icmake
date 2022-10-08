#include "scanner.ih"

void Scanner::assignIdent()
{
    s_matchIdent << matched();          // retrieve the directive identifier
    d_ident = s_matchIdent[1];          // assign it
}
