#include "scanner.ih"

void Scanner::undefDirective()
{
    if (not d_active)
        return;

    assignIdent();
    d_symtab.remove(d_ident);       // OK if d_ident wasn't defined
}
