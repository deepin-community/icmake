//#define XERR
#include "scanner.ih"

//  format: #define NAME 

void Scanner::defineDirective()
{
    xerr("");

    if (not d_active)
        return;

    begin(StartCondition_::define);

    assignIdent();                          // assign d_ident

    d_defineBuffer.clear();

    if (d_symtab.contains(d_ident))
        error() << '`' << d_ident << "' multiply defined\n";
}
