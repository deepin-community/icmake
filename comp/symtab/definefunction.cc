#define XERR
#include "symtab.ih"

void Symtab::defineFunction(ExprType type, string const &name)
{
    d_functions.define(type, name);

    d_var.resize(1);                    // only keep the global vars
    d_locals.clear();                   // start with no local variables
    push();
    SemVal::resetDead();
}
