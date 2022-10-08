#include "scanner.ih"

void Scanner::ifndefDirective()
{
    d_nest.push(d_active);

    if (d_active)                           // if the current level is active
    {
        assignIdent();                      // then get the #define ident:
        d_active = not d_symtab.contains(d_ident);  // remain active unless
                                                    // the ident was defined
    }
}
