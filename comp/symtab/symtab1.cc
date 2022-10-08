//#define XERR
#include "symtab.ih"

Symtab::Symtab(Functions &functions)
:
    d_functions(functions),
    d_var(1)
{}
