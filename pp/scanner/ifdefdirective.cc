#include "scanner.ih"

void Scanner::ifdefDirective()
{
    d_nest.push(d_active);

    if (d_active)           // only interpret if the current level is active
    {
        assignIdent();                          // get the ident: if #defined
        d_active = d_symtab.contains(d_ident);  // then remain active
    };
}
